#ifndef KPP_FIL_MaxStrLen_h
#define KPP_FIL_MaxStrLen_h

#include <KPP/InitWithArgs.h>
#include "MaxStrLen/Env.h"

typedef 
char FIL_Str_t[FIL_STRLEN];

typedef 
FIL_Str_t 
FIL_StrLong_t[FIL_STRLINE], 
FIL_StrLine_t[FIL_STRLINE];

ae2f_extern ae2f_SHAREDCALL
int FIL_StrLine_tInit(
		FIL_StrLine_t
		, int
		, const char**
		);

/// @brief for flexible API
#define FIL_StrLong_tInit FIL_StrLine_tInit

#endif
