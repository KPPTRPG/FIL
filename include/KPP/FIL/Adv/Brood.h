#ifndef FIL_Adv_Brood_h
#define FIL_Adv_Brood_h

#include "Stat.h"
#include <KPP/MaxStrLen.h>
#include <ae2f/Call.h>
#include <ae2f/Cast.h>
#include <KPP/InitWithArgs.h>

typedef struct FIL_AdvBrood {
	KPP_Str_t Name;
	KPP_StrLong_t Description;
	FIL_AdvStat Status;
} FIL_AdvBrood;

KPP_InitFuncDef(FIL_AdvBrood);

ae2f_extern ae2f_SHAREDCALL
void FIL_AdvBroodPrt(
	const FIL_AdvBrood* adv
	,FILE* ostream
);

#endif
