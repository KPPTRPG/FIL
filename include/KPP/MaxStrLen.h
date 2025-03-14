#ifndef KPP_FIL_MaxStrLen_h
#define KPP_FIL_MaxStrLen_h

#include "InitWithArgs.h"
#include "MaxStrLen/Env.h"
#include <stdio.h>

typedef 
char KPP_Str_t[KPP_STRLEN];

typedef 
KPP_Str_t 
KPP_StrLong_t[KPP_STRLINE], 
KPP_StrLine_t[KPP_STRLINE];

ae2f_extern ae2f_SHAREDCALL
int KPP_StrLine_tInit(
		KPP_StrLine_t
		, int
		, const char**
		);

/// @brief for flexible API
#define KPP_StrLong_tInit KPP_StrLine_tInit

ae2f_extern ae2f_SHAREDCALL
void KPP_StrLine_tPrt(
	const KPP_StrLine_t adv
	,FILE* ostream
);

#endif
