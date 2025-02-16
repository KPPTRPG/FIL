#include <FIL/Adv/Info.h>

ae2f_SHAREDEXPORT void FIL_AdvInfoPrint(
    const FIL_AdvInfo_t* data, FILE* out
) {
    fprintf(out, "Adv Info\n");
    FIL_GlobPrint(&data->Glob, out);
    fprintf(out, "Age: %u", data->Age);
    fprintf(out, "Gender: %s\n", data->Gender);
    fprintf(out, "Height: %u\n", data->Height);
    fprintf(out, "Weight: %u\n", data->Weight);

    #pragma region Bias
    fprintf(out, "Bias: ");
    if(!data->Bias) {
        fprintf(out, "Neutral\n");
    } else {
        switch(data->Bias & FIL_Bias_MASK0) {
            case FIL_Bias_CHAOS:
            fprintf(out, "Chaos ");
            break;
            case FIL_Bias_KHASSAR:
            fprintf(out, "Justified ");
            break;
            case FIL_Bias_NEUTRAL: default:
            fprintf(out, "Neautral ");
        }

        switch(data->Bias & FIL_Bias_MASK1) {
            case FIL_Bias_EVL:
            fprintf(out, "Evil\n");
            break;
            case FIL_Bias_TEMPLARI:
            fprintf(out, "Good\n");
            break;
            case FIL_Bias_NEUTRAL: default:
            fprintf(out, "Neautral\n");
        }
    }
    #pragma endregion

    FIL_AdvBroodPrint(&data->Brood, out);
}

#include <FIL/IO.h>
#include <FIL/Left.h>
#include <FIL/Flag.h>
#include <string.h>

ae2f_SHAREDEXPORT int FIL_AdvInfoScan(
    FIL_AdvInfo_t* buff, FILE* in, const char* pre
) {
    /// @brief contains "\0"
    const size_t 
        sl = pre ? strlen(pre) + 2 : 1,
        __s = sl - 1;

    FIL_Left_t __GlobPrefix = {0, };

    // exception. bad.
    if(sl + 1 >= FIL_FLAGMAXLEN) return 1;
    __GlobPrefix[__s] = FIL_FLAG_GLOB;

    LOOP_BEG:
    if(FIL_LeftLen != sl)
        return 0;
    for(size_t i = 0; i < __s; i++) {
        if(FIL_Left[i] != (__GlobPrefix[i] = pre[i]))
        return 0;
    }

    #pragma region Loop
    switch(FIL_Left[__s]) {
        case FIL_FLAG_ADV_INFO_AGE: {
            fscanf(in, "%u", &buff->Age);
        } break;
        case FIL_FLAG_ADV_INFO_GENDER: {
            fgets_space(buff->Gender, FIL_STRLEN, in);
        } break;
        case FIL_FLAG_ADV_INFO_HEIGHT: {
            fscanf(in, "%u", &buff->Height);
        } break;
        case FIL_FLAG_ADV_INFO_WEIGHT: {
            fscanf(in, "%u", &buff->Weight);
        } break;
        case FIL_FLAG_GLOB: {
            if(FIL_GlobScan(&buff->Glob, in, __GlobPrefix))
            return 1;
        } break;
        case FIL_FLAG_ADV_INFO_BIAS: {
            int ___[2];
            fscanf(in, "%u %u", ___, ___ + 1);
            buff->Bias = (___[0] & 0b11) | ((___[1] & 0b11) << 2);
        } break;
        default: return 0;
    }
    #pragma endregion

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