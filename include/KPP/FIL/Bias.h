#ifndef FIL_Bias_h
#define FIL_Bias_h

#include "../FIL.h"

/// @see FIL_Bias_MASK0
#define FIL_Bias_KHASSAR	0b0001

/// @see FIL_Bias_MASK0 
#define FIL_Bias_CHAOS		0b0010

/// @see FIL_Bias_KHASSAR
/// @see FIL_Bias_CHAOS
#define FIL_Bias_MASK0		0b0011
#define FIL_Bias_MASK_ORDER	FIL_Bias_MASK0

/// @see FIL_Bias_MASK1
#define FIL_Bias_TEMPLARI	0b0100
/// @see FIL_Bias_MASK1
#define FIL_Bias_EVL		0b1000

/// @see FIL_Bias_TEMPLARI
/// @see FIL_Bias_EVL
#define FIL_Bias_MASK1		0b1100
#define FIL_Bias_MASK_GOOD	FIL_Bias_MASK1

#define FIL_Bias_NEUTRAL	0

typedef uint8_t FIL_Bias_t;

#include <KPP/InitWithArgs.h>

KPP_InitFuncDef(FIL_Bias_t);

ae2f_extern ae2f_SHAREDCALL
void FIL_Bias_tPrt(
	FIL_Bias_t adv
	,FILE* ostream
);

#endif
