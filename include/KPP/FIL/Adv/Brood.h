#ifndef FIL_Adv_Brood_h
#define FIL_Adv_Brood_h

#include "Stat.h"
#include <KPP/FIL/MaxStrLen.h>
#include <ae2f/Call.h>
#include <ae2f/Cast.h>
#include <KPP/InitWithArgs.h>

typedef struct FIL_AdvBrood {
	FIL_Str_t Name;
	FIL_StrLong_t Description;
	FIL_AdvStat Status;
} FIL_AdvBrood;

KPP_InitFuncDef(FIL_AdvBrood);

#endif
