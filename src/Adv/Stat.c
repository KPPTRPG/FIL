#include <FIL/Adv/Stat.h>

#define ____print(mem) fprintf(out, #mem ": %u\n", data->mem);

ae2f_SHAREDEXPORT void FIL_AdvStatPrint(const FIL_AdvStat_t* data, FILE* out) {
    fprintf(out, "Adv Stat\n");
    ____print(LP);
    ____print(SP);
    ____print(STR);
    ____print(INT);
    ____print(CON);
    ____print(AGI);
    ____print(G);
}

#undef ____print


#include <FIL/Flag.h>
#include <FIL.h>
#include <FIL/IO.h>
#include <FIL/Left.h>
#include <FIL/Flag.h>
#include <string.h>

ae2f_SHAREDEXPORT int FIL_AdvStatScan(FIL_AdvStat_t* buff, FILE* in, const char* pre) {
    /// @brief contains "\0"
    const size_t 
        sl = pre ? strlen(pre) + 2 : 1,
        __s = sl - 1;
    // exception. bad.
    if(sl >= FIL_FLAGMAXLEN) return 1;

    LOOP_BEG:
    if(FIL_LeftLen != sl)
        return 0;
    for(size_t i = 0; i < __s; i++) {
        if(FIL_Left[i] != pre[i])
        return 0;
    }
    
    switch(FIL_Left[__s]) {
        case FIL_FLAG_ADV_STAT_AGI:
        fscanf(in, "%u", &buff->AGI);
        break;

        case FIL_FLAG_ADV_STAT_CON:
        fscanf(in, "%u", &buff->CON);
        break;

        case FIL_FLAG_ADV_STAT_G:
        fscanf(in, "%u", &buff->G);
        break;

        case FIL_FLAG_ADV_STAT_INT:
        fscanf(in, "%u", &buff->INT);
        break;

        case FIL_FLAG_ADV_STAT_LP:
        fscanf(in, "%u", &buff->LP);
        break;

        case FIL_FLAG_ADV_STAT_SP:
        fscanf(in, "%u", &buff->SP);
        break;

        case FIL_FLAG_ADV_STAT_STR:
        fscanf(in, "%u", &buff->STR);
        break;

        default: return 0;
    }

    if(!fgets_space(FIL_Left, sl, in))
    goto LOOP_END;

    FIL_LeftLen = strlen(FIL_Left) + 1;

    goto LOOP_BEG;
    LOOP_END:

    for(size_t i = 0; i < FIL_FLAGMAXLEN; i++)
    FIL_Left[i] = 0;
    FIL_LeftLen = 0;
    return 1;
}