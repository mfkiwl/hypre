/*
 * File:          bHYPRE_IJBuildMatrix_IOR.h
 * Symbol:        bHYPRE.IJBuildMatrix-v1.0.0
 * Symbol Type:   interface
 * Babel Version: 0.10.4
 * Description:   Intermediate Object Representation for bHYPRE.IJBuildMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.10.4
 */

#ifndef included_bHYPRE_IJBuildMatrix_IOR_h
#define included_bHYPRE_IJBuildMatrix_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "bHYPRE.IJBuildMatrix" (version 1.0.0)
 * 
 * This interface represents a linear-algebraic conceptual view of a
 * linear system.  The 'I' and 'J' in the name are meant to be
 * mnemonic for the traditional matrix notation A(I,J).
 * 
 */

struct bHYPRE_IJBuildMatrix__array;
struct bHYPRE_IJBuildMatrix__object;

/*
 * Forward references for external classes and interfaces.
 */

struct sidl_BaseInterface__array;
struct sidl_BaseInterface__object;
struct sidl_ClassInfo__array;
struct sidl_ClassInfo__object;
struct sidl_io_Deserializer__array;
struct sidl_io_Deserializer__object;
struct sidl_io_Serializer__array;
struct sidl_io_Serializer__object;

/*
 * Declare the method entry point vector.
 */

struct bHYPRE_IJBuildMatrix__epv {
  /* Implicit builtin methods */
  void* (*f__cast)(
    /* in */ void* self,
    /* in */ const char* name);
  void (*f__delete)(
    /* in */ void* self);
  void (*f__exec)(
    /* in */ void* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_io_Deserializer__object* inArgs,
    /* in */ struct sidl_io_Serializer__object* outArgs);
  char* (*f__getURL)(
    /* in */ void* self);
  /* Methods introduced in sidl.BaseInterface-v0.9.3 */
  void (*f_addRef)(
    /* in */ void* self);
  void (*f_deleteRef)(
    /* in */ void* self);
  sidl_bool (*f_isSame)(
    /* in */ void* self,
    /* in */ struct sidl_BaseInterface__object* iobj);
  struct sidl_BaseInterface__object* (*f_queryInt)(
    /* in */ void* self,
    /* in */ const char* name);
  sidl_bool (*f_isType)(
    /* in */ void* self,
    /* in */ const char* name);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ void* self);
  /* Methods introduced in bHYPRE.ProblemDefinition-v1.0.0 */
  int32_t (*f_SetCommunicator)(
    /* in */ void* self,
    /* in */ void* mpi_comm);
  int32_t (*f_Initialize)(
    /* in */ void* self);
  int32_t (*f_Assemble)(
    /* in */ void* self);
  int32_t (*f_GetObject)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object** A);
  /* Methods introduced in bHYPRE.IJBuildMatrix-v1.0.0 */
  int32_t (*f_SetLocalRange)(
    /* in */ void* self,
    /* in */ int32_t ilower,
    /* in */ int32_t iupper,
    /* in */ int32_t jlower,
    /* in */ int32_t jupper);
  int32_t (*f_SetValues)(
    /* in */ void* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* in */ struct sidl_double__array* values);
  int32_t (*f_AddToValues)(
    /* in */ void* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* in */ struct sidl_double__array* values);
  int32_t (*f_GetLocalRange)(
    /* in */ void* self,
    /* out */ int32_t* ilower,
    /* out */ int32_t* iupper,
    /* out */ int32_t* jlower,
    /* out */ int32_t* jupper);
  int32_t (*f_GetRowCounts)(
    /* in */ void* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* rows,
    /* inout */ struct sidl_int__array** ncols);
  int32_t (*f_GetValues)(
    /* in */ void* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* inout */ struct sidl_double__array** values);
  int32_t (*f_SetRowSizes)(
    /* in */ void* self,
    /* in */ struct sidl_int__array* sizes);
  int32_t (*f_Print)(
    /* in */ void* self,
    /* in */ const char* filename);
  int32_t (*f_Read)(
    /* in */ void* self,
    /* in */ const char* filename,
    /* in */ void* comm);
};

/*
 * Define the interface object structure.
 */

struct bHYPRE_IJBuildMatrix__object {
  struct bHYPRE_IJBuildMatrix__epv* d_epv;
  void*                             d_object;
};

/**
 * 
 * 
 * Anonymous class definition
 * 
 * 
 */
#ifndef included_bHYPRE_IJBuildMatrix_IOR_h
#include "bHYPRE_IJBuildMatrix_IOR.h"
#endif
#ifndef included_bHYPRE_ProblemDefinition_IOR_h
#include "bHYPRE_ProblemDefinition_IOR.h"
#endif
#ifndef included_sidl_BaseInterface_IOR_h
#include "sidl_BaseInterface_IOR.h"
#endif

/*
 * Symbol "bHYPRE._IJBuildMatrix" (version 1.0)
 */

struct bHYPRE__IJBuildMatrix__array;
struct bHYPRE__IJBuildMatrix__object;

/*
 * Declare the method entry point vector.
 */

struct bHYPRE__IJBuildMatrix__epv {
  /* Implicit builtin methods */
  void* (*f__cast)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* name);
  void (*f__delete)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  void (*f__exec)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_io_Deserializer__object* inArgs,
    /* in */ struct sidl_io_Serializer__object* outArgs);
  char* (*f__getURL)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  void (*f__ctor)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  void (*f__dtor)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  /* Methods introduced in sidl.BaseInterface-v0.9.3 */
  void (*f_addRef)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  void (*f_deleteRef)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  sidl_bool (*f_isSame)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj);
  struct sidl_BaseInterface__object* (*f_queryInt)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* name);
  sidl_bool (*f_isType)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* name);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  /* Methods introduced in bHYPRE.ProblemDefinition-v1.0.0 */
  int32_t (*f_SetCommunicator)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ void* mpi_comm);
  int32_t (*f_Initialize)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  int32_t (*f_Assemble)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self);
  int32_t (*f_GetObject)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* out */ struct sidl_BaseInterface__object** A);
  /* Methods introduced in bHYPRE.IJBuildMatrix-v1.0.0 */
  int32_t (*f_SetLocalRange)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ int32_t ilower,
    /* in */ int32_t iupper,
    /* in */ int32_t jlower,
    /* in */ int32_t jupper);
  int32_t (*f_SetValues)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* in */ struct sidl_double__array* values);
  int32_t (*f_AddToValues)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* in */ struct sidl_double__array* values);
  int32_t (*f_GetLocalRange)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* out */ int32_t* ilower,
    /* out */ int32_t* iupper,
    /* out */ int32_t* jlower,
    /* out */ int32_t* jupper);
  int32_t (*f_GetRowCounts)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* rows,
    /* inout */ struct sidl_int__array** ncols);
  int32_t (*f_GetValues)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ int32_t nrows,
    /* in */ struct sidl_int__array* ncols,
    /* in */ struct sidl_int__array* rows,
    /* in */ struct sidl_int__array* cols,
    /* inout */ struct sidl_double__array** values);
  int32_t (*f_SetRowSizes)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ struct sidl_int__array* sizes);
  int32_t (*f_Print)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* filename);
  int32_t (*f_Read)(
    /* in */ struct bHYPRE__IJBuildMatrix__object* self,
    /* in */ const char* filename,
    /* in */ void* comm);
  /* Methods introduced in bHYPRE._IJBuildMatrix-v1.0 */
};

/*
 * Define the class object structure.
 */

struct bHYPRE__IJBuildMatrix__object {
  struct bHYPRE_IJBuildMatrix__object     d_bhypre_ijbuildmatrix;
  struct bHYPRE_ProblemDefinition__object d_bhypre_problemdefinition;
  struct sidl_BaseInterface__object       d_sidl_baseinterface;
  struct bHYPRE__IJBuildMatrix__epv*      d_epv;
  void*                                   d_data;
};


#ifdef __cplusplus
}
#endif
#endif
