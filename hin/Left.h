#ifndef FIL_Left_h
#define FIL_Left_h

#include <stdint.h>

#include <ae2f/Call.h>
#include <ae2f/Cast.h>

/// @brief null terminator ('\0') is included on counting.
#define FIL_FLAGMAXLEN @FIL_FLAGMAXLEN@

typedef uint8_t FIL_Left_t[FIL_FLAGMAXLEN];

ae2f_extern ae2f_SHAREDCALL FIL_Left_t FIL_Left;

/// @brief null terminator ('\0') is included on counting.
ae2f_extern ae2f_SHAREDCALL size_t FIL_LeftLen;

#endif 