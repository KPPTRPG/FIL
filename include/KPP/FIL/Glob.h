#ifndef FIL_Glob_h
#define FIL_Glob_h

#include "../FIL.h"
#include <KPP/InitWithArgs.h>

/// @brief Global information for an object.
typedef struct FIL_Glob {
	KPP_Str_t 
		Name, 
		PLName, 
		Profile;

	KPP_StrLong_t 
		Background, 
		Etc;
} FIL_Glob;

KPP_InitFuncDef(FIL_Glob);

ae2f_extern ae2f_SHAREDCALL
void FIL_GlobPrt(
		const FIL_Glob* adv,
		FILE* ostream
		);

#endif
