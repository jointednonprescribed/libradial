
#ifndef _LIBRADIAL__DEF_H_
#define _LIBRADIAL__DEF_H_ 1

#ifndef _LIBRADIAL__CONFIG_H_
#	include "config.h"
#endif



/* LIBRADIAL_NO_CXX */
// Detect based on whether C++ is present
#ifndef LIBRADIAL_NO_CXX
#	ifdef __cplusplus
#		define LIBRADIAL_NO_CXX 0
#	else
#		define LIBRADIAL_NO_CXX 1
#	endif
// redefine overflowing false value
#elif LIBRADIAL_NO_CXX < 0
#	define LIBRADIAL_NO_CXX 0
// redefine overflowing true value
#elif LIBRADIAL_NO_CXX > 1
#	define LIBRADIAL_NO_CXX 1
#endif
// redefine if C++ is enabled but not present
#if LIBRADIAL_NO_CXX == 0 && !defined(__cplusplus)
#	define LIBRADIAL_NO_CXX 0
#endif


/* LRAD_EXTERN_C and LRAD_END_EXTERN_C */
#ifdef __cplusplus
#	define LRAD_EXTERN_C     extern "C" {
#	define LRAD_END_EXTERN_C }
#else
#	define LRAD_EXTERN_C
#	define LRAD_END_EXTERN_C
#endif

/* LRAD_CXX(...) */
#if LIBRADIAL_NO_CXX == 1
#	define LRAD_CXX(...)
#else
#	define LRAD_CXX(...) __VA_ARGS__
#endif

/* LRAD_BACKEND */
#define LRAD_BACKEND



#endif // _LIBRADIAL__DEF_H_
