#include <FIL/Adv.h>

/// @brief 
/// It must be stream, like stdin.
/// @param buff 
/// @param in 
/// @return 
ae2f_SHAREDEXPORT int FIL_AdvScan(FIL_Adv_t* buff, FILE* in) {
    buff[0] = (FIL_Adv_t) {0, };
}

/// @brief 
/// Displays the thing on output as CLI.
/// @param buff 
/// @param in 
/// @return 
ae2f_SHAREDEXPORT void FIL_AdvPrint(
    const FIL_Adv_t* data, 
    FILE* out
) {
    FIL_AdvInfoPrint(&data->Info, out);
    FIL_AdvStatPrint(&data->Stat, out);
}