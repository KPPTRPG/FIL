#ifndef FIL_Glob_h
#define FIL_Glob_h

#include "../FIL.h"
#include <KPP/InitWithArgs.h>

/// @brief Global information for an object.
typedef struct FIL_Glob {
	FIL_Str_t 
		Name, 
		PLName, 
		Profile;

	FIL_StrLong_t 
		Background, 
		Etc;
} FIL_Glob;

KPP_InitFuncDef(FIL_Glob);

#endif
