#ifndef KPP_InitWithArgs_h
#define KPP_InitWithArgs_h

#include <ae2f/Call.h>
#include <ae2f/Cast.h>

#define KPP_InitImp(type, _) \
	int type##Init( \
			type* _ \
			, int argc \
			, const char** argv \
			)

#define _KPP_InitFuncDef(type, _) \
	typedef int type##Init_t( \
			type* _ \
			, int argc \
			, const char** argv \
			); \
	ae2f_extern ae2f_SHAREDCALL type##Init_t type##Init


#define KPP_InitFuncDef(type) \
	_KPP_InitFuncDef(type, _)

#endif
