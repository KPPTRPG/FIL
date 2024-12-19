#ifndef FIL_Adv_Brood_h
#define FIL_Adv_Brood_h

// #include <FIL/Adv.h>
#include "Stat.h"
#include <FIL/MaxStrLen.h>
#include <ae2f/Call.h>
#include <ae2f/Cast.h>


typedef struct FIL_AdvBrood {
    FIL_Str_t Name;
    FIL_StrLong_t Description;
    FIL_AdvStat_t Status;
} FIL_AdvBrood_t;


#include <stdio.h>
ae2f_SHAREDCALL ae2f_extern void FIL_AdvBroodPrint(
    const FIL_AdvBrood_t* data, FILE* out
);

ae2f_SHAREDCALL ae2f_extern int FIL_AdvBroodScan(
    FIL_AdvBrood_t* buff, FILE* in, const char* pre
);

#endif