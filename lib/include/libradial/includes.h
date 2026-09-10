
#ifndef _LIBRADIAL__INCLUDES_H_
#define _LIBRADIAL__INCLUDES_H_ 1

#include "platform.h"



#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#include "string.h"
#include "limits.h"
#include "float.h"
#include "math.h"

#if LIBRADIAL_PLATFORM == LIBRADIAL_WINDOWS
#	include <windows.h>
#	include <winnt.h>
#elif LIBRADIAL_UNIXLIKE == true
#	include <unistd.h>
#	include <sys/types.h>
#endif



#endif // _LIBRADIAL__INCLUDES_H_
