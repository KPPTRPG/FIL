#ifndef FIL_Glob_h
#define FIL_Glob_h

#include "../FIL.h"

/// @brief Global information for an object.
typedef struct FIL_Glob {
    FIL_Str_t Name, PLName, Profile;
    FIL_StrLong_t Background, Etc;
} FIL_Glob_t;

#include <stdio.h>
#include <stdbool.h>

/// @brief 
/// Prints the Global strucure as a form of human readable.
/// @param data 
/// @param out 
/// @return 
ae2f_SHAREDCALL ae2f_extern void FIL_GlobPrint(const FIL_Glob_t* data, FILE* out);

/// @brief 
/// Ge
/// @param buff 
/// @param in 
/// @param pre Prefix for the arg flag
/// @return 
/// 0: It should continue. \n
/// 1: It should be done.
ae2f_SHAREDCALL ae2f_extern int FIL_GlobScan(FIL_Glob_t* buff, FILE* in, const char* pre);

#endif