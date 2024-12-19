#ifndef FIL_Adv_h
#define FIL_Adv_h

#include "Glob.h"
#include "Bias.h"
#include "Adv/Brood.h"

#include "Adv/Info.h"
#include "Adv/Stat.h"


typedef struct FIL_Adv {
    FIL_AdvInfo_t Info;
    FIL_AdvStat_t Stat;
} FIL_Adv_t;

#include <stdio.h>

/// @brief 
/// Displays the thing on output as CLI.
/// @param data {const FIL_Adv_t*}
/// @param out {FILE*}
/// @return 
#define FIL_AdvSave(data, out) fwrite(data, sizeof(FIL_Adv_t), 1, out)

/// @brief 
/// It must be stream, like stdin.
/// @param buff {FIL_Adv_t*}
/// @param in {FILE*}
/// @return 
#define FIL_AdvLoad(buff, in) fread(buff, sizeof(FIL_Adv_t), 1, in)

/// @brief 
/// It must be stream, like stdin.
/// @param buff 
/// @param in 
/// @return 
ae2f_SHAREDCALL ae2f_extern int FIL_AdvScan(FIL_Adv_t* buff, FILE* in);

/// @brief 
/// Displays the thing on output as CLI.
/// @param buff 
/// @param in 
/// @return 
ae2f_SHAREDCALL ae2f_extern void FIL_AdvPrint(const FIL_Adv_t* buff, FILE* out);

#endif