#ifndef FIL_Adv_Stat_h
#define FIL_Adv_Stat_h

#include <stdint.h>

typedef struct FIL_AdvStat {
    uint32_t LP, SP, STR, AGI, CON, INT, G;
} FIL_AdvStat_t;

#include <stdio.h>
#include <ae2f/Call.h>
#include <ae2f/Cast.h>

ae2f_SHAREDCALL ae2f_extern void FIL_AdvStatPrint(const FIL_AdvStat_t* data, FILE* out);
ae2f_SHAREDCALL ae2f_extern int FIL_AdvStatScan(
    FIL_AdvStat_t* data, 
    FILE* in, 
    const char* pre
);

#endif