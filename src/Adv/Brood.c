#include <FIL/Adv/Brood.h>
ae2f_SHAREDEXPORT void FIL_AdvBroodPrint(
    const FIL_AdvBrood_t* data, FILE* out
) {
    fprintf(out, "Brood\n");
    fprintf(out, "Name: %s\n", data->Name);
    fprintf(out, "Description:\n%s\n\n", data->Description);
}

#include <FIL/IO.h>
#include <FIL/Flag.h>
#include <FIL/Left.h>

ae2f_SHAREDEXPORT int FIL_AdvBroodScan(
    FIL_AdvBrood_t* buff, FILE* in, const char* pre
) {
    /// @brief contains "\0"
    const size_t 
        sl = pre ? strlen(pre) + 2 : 1,
        __s = sl - 1;

    FIL_Left_t __StatPrefix = {0, };

    // exception. bad.
    if(sl + 1 >= FIL_FLAGMAXLEN) return 1;
    __StatPrefix[__s] = FIL_FLAG_ADV_STAT; // for stat

    LOOP_BEG:

    #pragma region LOOP
    #error TODO: implement this shit
    switch(FIL_Left[__s]) {
        case FIL_FLAG_ADV_BROOD_NAME: {

        }
        case FIL_FLAG_ADV_BROOD_DESC: {

        }
        case FIL_FLAG_ADV_BROOD_STAT: {
            if(FIL_AdvStatScan(&buff->Status, in, __StatPrefix))
            return 1;
        }
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
    return 0;
}