#include <FIL/Glob.h>
#include <string.h>
#include <FIL/Flag.h>
#include <FIL/IO.h>
#include <stdlib.h>

ae2f_SHAREDEXPORT void FIL_GlobPrint(const FIL_Glob_t* data, FILE* out) {
    fprintf(out, "Glob\n");
    fprintf(out, "Name: %s\n", data->Name);
    fprintf(out, "Player Name: %s\n", data->PLName);
    fprintf(out, "Profile: \n%s\n", data->Profile);
    fprintf(out, "Background Story:\n%s\n\n", data->Background);
    fprintf(out, "Etc:\n%s\n\n", data->Etc);
}

#define __esc 27

static _Bool FIL_GlobScan_Imp(
    FIL_Glob_t* buff, 
    FILE* in, 
    char got
) {
    int bg_size = 0, etc_size = 0, gotchar = 0;
    switch(got) {
        case FIL_FLAG_GLOB_NAME:
        fgets_space(buff->Name, sizeof(buff->Name), in);
        break;
        case FIL_FLAG_GLOB_PLNAME:
        fgets_space(buff->PLName, sizeof(buff->PLName), in);
        break;
        case FIL_FLAG_GLOB_PROFILE:
        fgets_space(buff->Profile, sizeof(buff->Profile), in);
        break;
        case FIL_FLAG_GLOB_BG:
        gotchar = 0;
        while(gotchar != __esc && bg_size < FIL_STRLEN_LONG && gotchar != EOF) {
            fgets(buff->Background + bg_size, sizeof(buff->Background) - bg_size, in);
            bg_size = strcspn(buff->Background + bg_size, "\n");
            gotchar = fgetc(in);
        }
        break;
        case FIL_FLAG_GLOB_ETC:
        gotchar = 0;
        while(gotchar != __esc && etc_size < FIL_STRLEN_LONG) {
            fgets(buff->Etc + etc_size, sizeof(buff->Etc) - etc_size, in);
            etc_size = strcspn(buff->Etc + bg_size, "\n");
            gotchar = fgetc(in);
        }
        break;
        default: return 1;
    }
    return 1;
}

#include <FIL/Left.h>

ae2f_SHAREDEXPORT int FIL_GlobScan(FIL_Glob_t* buff, FILE* in, const char* pre) {
    /// @brief contains "\0"
    const size_t 
        sl = pre ? strlen(pre) + 2 : 1,
        __s = sl - 1;

    int bg_size = 0, etc_size = 0, gotchar = 0;

    // exception. bad.
    if(sl >= FIL_FLAGMAXLEN) return 0;

    loop_start:

    if(FIL_LeftLen != sl)
    return 0;

    for(size_t i = 0; i < __s; i++) {
        if(FIL_Left[i] != pre[i])
        return 0;
    }

    switch(FIL_Left[__s]) {
        case FIL_FLAG_GLOB_NAME:
        fgets_space(buff->Name, sizeof(buff->Name), in);
        break;
        case FIL_FLAG_GLOB_PLNAME:
        fgets_space(buff->PLName, sizeof(buff->PLName), in);
        break;
        case FIL_FLAG_GLOB_PROFILE:
        fgets_space(buff->Profile, sizeof(buff->Profile), in);
        break;
        case FIL_FLAG_GLOB_BG:
        gotchar = 0;
        while(gotchar != __esc && bg_size < FIL_STRLEN_LONG) {
            fgets(buff->Background + bg_size, sizeof(buff->Background) - bg_size, in);
            bg_size = strcspn(buff->Background + bg_size, "\n");
            gotchar = fgetc(in);
        }
        break;
        case FIL_FLAG_GLOB_ETC:
        gotchar = 0;
        while(gotchar != __esc && etc_size < FIL_STRLEN_LONG) {
            fgets(buff->Etc + etc_size, sizeof(buff->Etc) - etc_size, in);
            etc_size = strcspn(buff->Etc + bg_size, "\n");
            gotchar = fgetc(in);
        }
        break;
        default: return 0;
    }
    return 0;

    if(!fgets_space(FIL_Left, FIL_FLAGMAXLEN, in))
    goto ___gone;

    FIL_LeftLen = strlen(FIL_Left) + 1;
    goto loop_start;

    ___gone:
    for(size_t i = 0; i < FIL_FLAGMAXLEN; i++)
    FIL_Left[i] = 0;
    FIL_LeftLen = 0;
    return 1;
}