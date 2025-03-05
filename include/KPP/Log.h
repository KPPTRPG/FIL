#include "Log/Log.h"

#define _KPP_NONE

#if KPP_LOG
#include <stdio.h>
#include <ae2f/Cast.h>

#define _KPP_WhenLog(...)		__VA_ARGS__
#define _KPP_WhenNLog(...)		_KPP_NONE
#else
#define _KPP_WhenLog(...)		_KPP_NONE
#define _KPP_WhenNLog(...)		__VA_ARGS__
#endif

#define _KPP_invoke(f, ...)		_KPP_WhenLog(f(__VA_ARGS__))
#define _KPP_puts(key, str)		_KPP_invoke(puts, key str)

#define _KPP_printf(key, format, ...)	_KPP_invoke(printf, key format, __VA_ARGS__)

#define KPP_puts(str)			_KPP_puts("[LOG] ", str)
#define KPP_printf(format, ...) 	_KPP_printf("[LOG] ", format, __VA_ARGS__)

#define KPP_putserr(str)		_KPP_puts("[ERR] ", str)
#define KPP_printferr(format, ...)	_KPP_printf("[ERR] ", format, __VA_ARGS__)
