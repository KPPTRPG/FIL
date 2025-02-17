#ifndef FIL_IO_h
#define FIL_IO_h

#include <FIL.h>
#include <stdio.h>

/// @brief fgets with block for space (' ')
/// @param buff 
/// @param num 
/// @param stream 
/// @return 
ae2f_extern ae2f_SHAREDCALL char* fgets_space(
    char* buff, int num, 
    FILE* stream
);

ae2f_extern ae2f_SHAREDCALL char* fgets_termed(
    char* buff, int num, 
    const char* _term, size_t _termc, 
    FILE* stream
);

#endif