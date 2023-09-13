/******************************************************************************
 * Copyright (c) 1998 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

/******************************************************************************
 *
 * Header info for Vector data structure
 *
 *****************************************************************************/

#ifndef hypre_VECTOR_HEADER
#define hypre_VECTOR_HEADER

/*--------------------------------------------------------------------------
 * hypre_Vector
 *--------------------------------------------------------------------------*/

typedef struct
{
   HYPRE_Complex        *data;
   HYPRE_Int             size;      /* Number of elements of a single vector component */
   HYPRE_Int             component; /* Index of a multivector component
                                    (used for set/get routines )*/
   HYPRE_Int             owns_data;  /* Does the Vector create/destroy `data'? */
   HYPRE_MemoryLocation  memory_location; /* memory location of data array */

   /* For multivectors...*/
   HYPRE_Int   num_vectors;  /* the above "size" is size of one vector */
   HYPRE_Int   multivec_storage_method;
   /* ...if 0, store colwise v0[0], v0[1], ..., v1[0], v1[1], ... v2[0]... */
   /* ...if 1, store rowwise v0[0], v1[0], ..., v0[1], v1[1], ... */
   /* With colwise storage, vj[i] = data[ j*size + i]
      With rowwise storage, vj[i] = data[ j + num_vectors*i] */
   HYPRE_Int  vecstride, idxstride;
   /* ... so vj[i] = data[ j*vecstride + i*idxstride ] regardless of row_storage.*/

#if defined(HYPRE_MIXED_PRECISION)   
   HYPRE_Precision vector_precision;
#endif 

} hypre_Vector;

typedef struct
{
   void        *data;
   HYPRE_Int             size;      /* Number of elements of a single vector component */
   HYPRE_Int             component; /* Index of a multivector component
                                    (used for set/get routines )*/
   HYPRE_Int             owns_data;  /* Does the Vector create/destroy `data'? */
   HYPRE_MemoryLocation  memory_location; /* memory location of data array */

   /* For multivectors...*/
   HYPRE_Int   num_vectors;  /* the above "size" is size of one vector */
   HYPRE_Int   multivec_storage_method;
   /* ...if 0, store colwise v0[0], v0[1], ..., v1[0], v1[1], ... v2[0]... */
   /* ...if 1, store rowwise v0[0], v1[0], ..., v0[1], v1[1], ... */
   /* With colwise storage, vj[i] = data[ j*size + i]
      With rowwise storage, vj[i] = data[ j + num_vectors*i] */
   HYPRE_Int  vecstride, idxstride;
   /* ... so vj[i] = data[ j*vecstride + i*idxstride ] regardless of row_storage.*/

#if defined(HYPRE_MIXED_PRECISION)   
   HYPRE_Precision vector_precision;
#endif 

} hypre_Vector_mp;

/*--------------------------------------------------------------------------
 * Accessor functions for the Vector structure
 *--------------------------------------------------------------------------*/

#define hypre_VectorData(vector)                  ((vector) -> data)
#define hypre_VectorSize(vector)                  ((vector) -> size)
#define hypre_VectorComponent(vector)             ((vector) -> component)
#define hypre_VectorOwnsData(vector)              ((vector) -> owns_data)
#define hypre_VectorMemoryLocation(vector)        ((vector) -> memory_location)
#define hypre_VectorNumVectors(vector)            ((vector) -> num_vectors)
#define hypre_VectorMultiVecStorageMethod(vector) ((vector) -> multivec_storage_method)
#define hypre_VectorVectorStride(vector)          ((vector) -> vecstride)
#define hypre_VectorIndexStride(vector)           ((vector) -> idxstride)

#if defined(HYPRE_MIXED_PRECISION)   
#define hypre_VectorPrecision(vector)          ((vector) -> vector_precision)
#endif

#endif
