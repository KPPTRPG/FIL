#ifndef FIL_Adv_Info_h
#define FIL_Adv_Info_h

#include "Brood.h"
#include <KPP/FIL.h>
#include <KPP/FIL/Glob.h>
#include <KPP/FIL/Bias.h>

typedef struct FIL_AdvInfo {
	KPP_Str_t Gender;
	uint32_t Height, Weight, Age;
	FIL_Bias_t Bias;
	FIL_AdvBrood Brood;
	FIL_Glob Glob;
} FIL_AdvInfo;

#include <KPP/InitWithArgs.h>
KPP_InitFuncDef(FIL_AdvInfo);

ae2f_extern ae2f_SHAREDCALL
void FIL_AdvInfoPrt(
		const FIL_AdvInfo* adv
		, FILE* ostream
		);

#endif
