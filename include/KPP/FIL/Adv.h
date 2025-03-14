#ifndef FIL_Adv_h
#define FIL_Adv_h

#include "Glob.h"
#include "Bias.h"
#include "Adv/Brood.h"
#include "Adv/Info.h"
#include "Adv/Stat.h"

typedef struct FIL_Adv {
	FIL_AdvInfo Info;
	FIL_AdvStat Stat;
} FIL_Adv;

#include <KPP/InitWithArgs.h>

KPP_InitFuncDef(FIL_Adv);

#include <ae2f/errGlob.h>
#include <stdio.h>

/**
 * 
 * Imp Done.
 * */
ae2f_extern ae2f_SHAREDCALL
void FIL_AdvPrt(
	const FIL_Adv* adv
	,FILE* ostream
);

#endif
