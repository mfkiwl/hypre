/*BHEADER**********************************************************************
 * (c) 1999   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/
/******************************************************************************
 *
 * DiagScale - Diagonal scaling.
 *
 *****************************************************************************/

#include <stdlib.h>
#include "math.h"
#include "Common.h"
#include "Matrix.h"
#include "RowPatt.h"
#include "DiagScale.h"
#include "OrderStat.h"

#define DIAG_VALS_TAG      225
#define DIAG_INDS_TAG      226

/*--------------------------------------------------------------------------
 * ExchangeDiagEntries - Given a list of indices of diagonal entries required
 * by this processor, "reqind" of length "reqlen", return a list of 
 * corresponding diagonal entries, "diags".  Used internally only by
 * DiagScaleCreate.
 *
 * comm   - MPI communicator (input)
 * mat    - matrix used to map row and column numbers to processors (input)
 * reqlen - length of request list (input)
 * reqind - list of indices (input)
 * diags  - corresponding list of diagonal entries (output)
 * num_requests - number of requests (output)
 * requests - request handles, used to check that all responses are back 
 *            (output)
 *--------------------------------------------------------------------------*/

static void ExchangeDiagEntries(MPI_Comm comm, Matrix *mat, int reqlen, 
  int *reqind, double *diags, int *num_requests, MPI_Request *requests,
  int *replies_list)
{
    MPI_Request request;
    int i, j, this_pe;

    shell_sort(reqlen, reqind);

    *num_requests = 0;

    for (i=0; i<reqlen; i=j) /* j is set below */
    {
        /* The processor that owns the row with index reqind[i] */
        this_pe = MatrixRowPe(mat, reqind[i]);

        /* Figure out other rows we need from this_pe */
        for (j=i+1; j<reqlen; j++)
        {
            /* if row is on different pe */
            if (reqind[j] < mat->beg_rows[this_pe] ||
                reqind[j] > mat->end_rows[this_pe])
                   break;
        }

        /* Post receive for diagonal values */
        MPI_Irecv(&diags[i], j-i, MPI_DOUBLE, this_pe, DIAG_VALS_TAG, 
	    comm, &requests[*num_requests]);

        /* Request rows in reqind[i..j-1] */
        MPI_Isend(&reqind[i], j-i, MPI_INT, this_pe, DIAG_INDS_TAG,
            comm, &request);
        MPI_Request_free(&request);
        (*num_requests)++;

	if (replies_list != NULL)
	    replies_list[this_pe] = 1;
    }
}

/*--------------------------------------------------------------------------
 * ExchangeDiagEntriesServer - Receive requests for diagonal entries and
 * send replies.  Used internally only by DiagScaleCreate.
 * 
 * comm   - MPI communicator (input)
 * mat    - matrix used to map row and column numbers to processors (input)
 * local_diags - local diagonal entries (input)
 * num_requests - number of requests to be received (input)
 *--------------------------------------------------------------------------*/

static void ExchangeDiagEntriesServer(MPI_Comm comm, Matrix *mat, 
  double *local_diags, int num_requests)
{
    MPI_Request request;
    MPI_Status status;
    int *recvbuf = NULL;
    double *sendbuf = NULL;
    int i, j, source, count;
    int buflen = 0;

    /* recvbuf contains requested indices */
    /* sendbuf contains corresponding diagonal entries */

    /* Use this request handle to check that the send buffer is clear */
    request = MPI_REQUEST_NULL;

    for (i=0; i<num_requests; i++)
    {
        MPI_Probe(MPI_ANY_SOURCE, DIAG_INDS_TAG, comm, &status);
        source = status.MPI_SOURCE;
	MPI_Get_count(&status, MPI_INT, &count);

        if (count > buflen)
	{
	    free(recvbuf);
	    free(sendbuf);
	    buflen = count;
            recvbuf = (int *)    malloc(buflen * sizeof(int));
            sendbuf = (double *) malloc(buflen * sizeof(double));
	}

        MPI_Recv(recvbuf, buflen, MPI_INT, MPI_ANY_SOURCE, 
	    DIAG_INDS_TAG, comm, &status);
        source = status.MPI_SOURCE;

	/* Wait until send buffer is clear */
	MPI_Wait(&request, &status);

	/* Construct reply message of diagonal entries in sendbuf */
        for (j=0; j<count; j++)
	    sendbuf[j] = local_diags[recvbuf[j] - mat->beg_row];

	/* Use ready-mode send, since receives already posted */
	MPI_Irsend(sendbuf, count, MPI_DOUBLE, source, 
	    DIAG_VALS_TAG, comm, &request);
    }

    /* Wait for final send to complete before freeing sendbuf */
    MPI_Wait(&request, &status);

    free(recvbuf);
    free(sendbuf);
}

/*--------------------------------------------------------------------------
 * DiagScaleCreate - Return (a pointer to) a diagonal scaling object.
 * Scale using the diagonal of A.  Use the list of external indices
 * from the numbering object "numb".
 *--------------------------------------------------------------------------*/

DiagScale *DiagScaleCreate(Matrix *A, Numbering *numb)
{
    MPI_Request *requests;
    MPI_Status  *statuses;
    int npes, row, i, j, num_requests, num_replies, *replies_list;
    int len, *ind;
    double *val;

    DiagScale *p = (DiagScale *) malloc(sizeof(DiagScale));

    /* Storage for local diagonal entries */
    p->local_diags = (double *) 
        malloc((A->end_row - A->beg_row + 1) * sizeof(double));

    /* Extract the local diagonal entries */
    for (row=0; row<=A->end_row - A->beg_row; row++)
    {
	MatrixGetRow(A, row, &len, &ind, &val);

        p->local_diags[row] = 1.0; /* in case no diag entry */

        for (j=0; j<len; j++)
        {
            if (ind[j] == row)
            {
                if (val[j] != 0.0)
                    p->local_diags[row] = 1.0 / sqrt(ABS(val[j]));
                break;
            }
        }
    }

    /* Get the list of diagonal indices that we need.
       This is simply the external indices */
    /* ExchangeDiagEntries will sort the list - so give it a copy */
    len = numb->num_ind - numb->num_loc;
    ind = (int *) malloc(len * sizeof(int));
    memcpy(ind, &numb->local_to_global[numb->num_loc], len * sizeof(int));

    /* buffer for receiving diagonal values from other processors */
    p->ext_diags = (double *) malloc(len * sizeof(double));

    MPI_Comm_size(A->comm, &npes);
    requests = (MPI_Request *) malloc(npes * sizeof(MPI_Request));
    statuses = (MPI_Status  *) malloc(npes * sizeof(MPI_Status));
    replies_list = (int *) calloc(npes, sizeof(int));

    ExchangeDiagEntries(A->comm, A, len, ind, p->ext_diags, &num_requests, 
        requests, replies_list);

    num_replies = FindNumReplies(A->comm, replies_list);
    free(replies_list);

    ExchangeDiagEntriesServer(A->comm, A, p->local_diags, num_replies);

    /* Wait for all replies */
    MPI_Waitall(num_requests, requests, statuses);
    free(requests);
    free(statuses);
    free(ind);

    p->offset = A->end_row - A->beg_row + 1;

    return p;
}

/*--------------------------------------------------------------------------
 * DiagScaleDestroy - Destroy a diagonal scale object.
 *--------------------------------------------------------------------------*/

void DiagScaleDestroy(DiagScale *p)
{
    free(p->local_diags);
    free(p->ext_diags);

    free(p);
}

/*--------------------------------------------------------------------------
 * DiagScaleGet -  Returns scale factor given a row number in local indexing.
 * The factor is the reciprocal of the square root of the diagonal entry.
 *--------------------------------------------------------------------------*/

double DiagScaleGet(DiagScale *p, int index)
{
    if (index < p->offset)
    {
        return p->local_diags[index];
    }
    else
    {
        return p->ext_diags[index - p->offset];
    }
}
