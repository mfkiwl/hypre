/*** DO NOT EDIT THIS FILE DIRECTLY (use 'lapack_func_header' to generate) ***/

/******************************************************************************
 * Copyright (c) 1998 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

/******************************************************************************
 * Header file for transforming multiprecision functions names
 *****************************************************************************/

#ifndef LAPACK_MUP_FUNC_HEADER
#define LAPACK_MUP_FUNC_HEADER

#include "multiprecision.h"

#define hypre_dbdsqr HYPRE_MULTIPRECISION_FUNC ( hypre_dbdsqr )
#define hypre_dgebd2 HYPRE_MULTIPRECISION_FUNC ( hypre_dgebd2 )
#define hypre_dgebrd HYPRE_MULTIPRECISION_FUNC ( hypre_dgebrd )
#define hypre_dgelq2 HYPRE_MULTIPRECISION_FUNC ( hypre_dgelq2 )
#define hypre_dgelqf HYPRE_MULTIPRECISION_FUNC ( hypre_dgelqf )
#define hypre_dgels HYPRE_MULTIPRECISION_FUNC ( hypre_dgels )
#define hypre_dgeqr2 HYPRE_MULTIPRECISION_FUNC ( hypre_dgeqr2 )
#define hypre_dgeqrf HYPRE_MULTIPRECISION_FUNC ( hypre_dgeqrf )
#define hypre_dgesvd HYPRE_MULTIPRECISION_FUNC ( hypre_dgesvd )
#define hypre_dgetf2 HYPRE_MULTIPRECISION_FUNC ( hypre_dgetf2 )
#define hypre_dgetrf HYPRE_MULTIPRECISION_FUNC ( hypre_dgetrf )
#define hypre_dgetri HYPRE_MULTIPRECISION_FUNC ( hypre_dgetri )
#define hypre_dgetrs HYPRE_MULTIPRECISION_FUNC ( hypre_dgetrs )
#define hypre_dlabad HYPRE_MULTIPRECISION_FUNC ( hypre_dlabad )
#define hypre_dlabrd HYPRE_MULTIPRECISION_FUNC ( hypre_dlabrd )
#define hypre_dlacpy HYPRE_MULTIPRECISION_FUNC ( hypre_dlacpy )
#define hypre_dlae2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlae2 )
#define hypre_dlaev2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlaev2 )
#define hypre_dlamc1 HYPRE_MULTIPRECISION_FUNC ( hypre_dlamc1 )
#define hypre_dlamc2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlamc2 )
#define hypre_dlamc3 HYPRE_MULTIPRECISION_FUNC ( hypre_dlamc3 )
#define hypre_dlamc4 HYPRE_MULTIPRECISION_FUNC ( hypre_dlamc4 )
#define hypre_dlamc5 HYPRE_MULTIPRECISION_FUNC ( hypre_dlamc5 )
#define hypre_dlamch HYPRE_MULTIPRECISION_FUNC ( hypre_dlamch )
#define hypre_dlange HYPRE_MULTIPRECISION_FUNC ( hypre_dlange )
#define hypre_dlanst HYPRE_MULTIPRECISION_FUNC ( hypre_dlanst )
#define hypre_dlansy HYPRE_MULTIPRECISION_FUNC ( hypre_dlansy )
#define hypre_dlapy2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlapy2 )
#define hypre_dlarf HYPRE_MULTIPRECISION_FUNC ( hypre_dlarf )
#define hypre_dlarfb HYPRE_MULTIPRECISION_FUNC ( hypre_dlarfb )
#define hypre_dlarfg HYPRE_MULTIPRECISION_FUNC ( hypre_dlarfg )
#define hypre_dlarft HYPRE_MULTIPRECISION_FUNC ( hypre_dlarft )
#define hypre_dlartg HYPRE_MULTIPRECISION_FUNC ( hypre_dlartg )
#define hypre_dlas2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlas2 )
#define hypre_dlascl HYPRE_MULTIPRECISION_FUNC ( hypre_dlascl )
#define hypre_dlaset HYPRE_MULTIPRECISION_FUNC ( hypre_dlaset )
#define hypre_dlasq1 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq1 )
#define hypre_dlasq2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq2 )
#define hypre_dlasq3 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq3 )
#define hypre_dlasq4 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq4 )
#define hypre_dlasq5 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq5 )
#define hypre_dlasq6 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasq6 )
#define hypre_dlasr HYPRE_MULTIPRECISION_FUNC ( hypre_dlasr )
#define hypre_dlasrt HYPRE_MULTIPRECISION_FUNC ( hypre_dlasrt )
#define hypre_dlassq HYPRE_MULTIPRECISION_FUNC ( hypre_dlassq )
#define hypre_dlasv2 HYPRE_MULTIPRECISION_FUNC ( hypre_dlasv2 )
#define hypre_dlaswp HYPRE_MULTIPRECISION_FUNC ( hypre_dlaswp )
#define hypre_dlatrd HYPRE_MULTIPRECISION_FUNC ( hypre_dlatrd )
#define hypre_dorg2l HYPRE_MULTIPRECISION_FUNC ( hypre_dorg2l )
#define hypre_dorg2r HYPRE_MULTIPRECISION_FUNC ( hypre_dorg2r )
#define hypre_dorgbr HYPRE_MULTIPRECISION_FUNC ( hypre_dorgbr )
#define hypre_dorgl2 HYPRE_MULTIPRECISION_FUNC ( hypre_dorgl2 )
#define hypre_dorglq HYPRE_MULTIPRECISION_FUNC ( hypre_dorglq )
#define hypre_dorgql HYPRE_MULTIPRECISION_FUNC ( hypre_dorgql )
#define hypre_dorgqr HYPRE_MULTIPRECISION_FUNC ( hypre_dorgqr )
#define hypre_dorgtr HYPRE_MULTIPRECISION_FUNC ( hypre_dorgtr )
#define hypre_dorm2r HYPRE_MULTIPRECISION_FUNC ( hypre_dorm2r )
#define hypre_dormbr HYPRE_MULTIPRECISION_FUNC ( hypre_dormbr )
#define hypre_dorml2 HYPRE_MULTIPRECISION_FUNC ( hypre_dorml2 )
#define hypre_dormlq HYPRE_MULTIPRECISION_FUNC ( hypre_dormlq )
#define hypre_dormqr HYPRE_MULTIPRECISION_FUNC ( hypre_dormqr )
#define hypre_dpotf2 HYPRE_MULTIPRECISION_FUNC ( hypre_dpotf2 )
#define hypre_dpotrf HYPRE_MULTIPRECISION_FUNC ( hypre_dpotrf )
#define hypre_dpotrs HYPRE_MULTIPRECISION_FUNC ( hypre_dpotrs )
#define hypre_dsteqr HYPRE_MULTIPRECISION_FUNC ( hypre_dsteqr )
#define hypre_dsterf HYPRE_MULTIPRECISION_FUNC ( hypre_dsterf )
#define hypre_dsyev HYPRE_MULTIPRECISION_FUNC ( hypre_dsyev )
#define hypre_dsygs2 HYPRE_MULTIPRECISION_FUNC ( hypre_dsygs2 )
#define hypre_dsygst HYPRE_MULTIPRECISION_FUNC ( hypre_dsygst )
#define hypre_dsygv HYPRE_MULTIPRECISION_FUNC ( hypre_dsygv )
#define hypre_dsytd2 HYPRE_MULTIPRECISION_FUNC ( hypre_dsytd2 )
#define hypre_dsytrd HYPRE_MULTIPRECISION_FUNC ( hypre_dsytrd )
#define hypre_dtrti2 HYPRE_MULTIPRECISION_FUNC ( hypre_dtrti2 )
#define hypre_dtrtri HYPRE_MULTIPRECISION_FUNC ( hypre_dtrtri )
#define hypre_ieeeck HYPRE_MULTIPRECISION_FUNC ( hypre_ieeeck )
#define hypre_ilaenv HYPRE_MULTIPRECISION_FUNC ( hypre_ilaenv )
#define hypre_lapack_lsame HYPRE_MULTIPRECISION_FUNC ( hypre_lapack_lsame )
#define hypre_lapack_xerbla HYPRE_MULTIPRECISION_FUNC ( hypre_lapack_xerbla )

#endif
