#ifndef FIL_Adv_Info_h
#define FIL_Adv_Info_h

#include "Brood.h"
#include <FIL.h>
#include <FIL/Glob.h>
#include "../Bias.h"

typedef struct FIL_AdvInfo {
    FIL_Str_t Gender;
    uint32_t Height, Weight, Age;
    FIL_Bias_t Bias;
    FIL_AdvBrood_t Brood;
    FIL_Glob_t Glob;
} FIL_AdvInfo_t;

#include <stdio.h>
ae2f_SHAREDCALL ae2f_extern void FIL_AdvInfoPrint(
    const FIL_AdvInfo_t* data, FILE* out
);

ae2f_SHAREDCALL ae2f_extern int FIL_AdvInfoScan(
    FIL_AdvInfo_t* buff, FILE* in, const char* pre
);

#endif