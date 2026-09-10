
#ifndef _LIBRADIAL__PLATFORM_H_
#define _LIBRADIAL__PLATFORM_H_ 1

#ifndef _LIBRADIAL__DEF_H_
#	include "def.h"
#endif



#define LIBRADIAL_UNKNOWN    0
#define LIBRADIAL_LINUX      1
#define LIBRADIAL_WINDOWS    2
#define LIBRADIAL_OSX        3
#define LIBRADIAL_BSD        4
#define LIBRADIAL_WASM       5
#define LIBRADIAL_GCC        6
#define LIBRADIAL_CLANG      7
#define LIBRADIAL_MSVC       8
#define LIBRADIAL_EMSCRIPTEN 9

#ifdef _WIN32
#	define LIBRADIAL_PLATFORM LIBRADIAL_WINDOWS
#	define LIBRADIAL_UNIXLIKE false
#	ifdef __GNUC__
#		define LIBRADIAL_COMPILER LIBRADIAL_GCC
#	endif
#	ifndef _WIN64
#		define LIBRADIAL_PLATFORM32 false
#	else
#		define LIBRADIAL_PLATFORM32 true
#	endif

#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux__)
#	define LIBRADIAL_PLATFORM LIBRADIAL_LINUX
#	define LIBRADIAL_UNIXLIKE true
#	ifdef __GNUC__
#		define LIBRADIAL_COMPILER LIBRADIAL_GCC
#	endif
#	ifdef __LP64__
#		define LIBRADIAL_PLATFORM32 false
#	else
#		define LIBRADIAL_PLATFORM32 true
#	endif

#elif defined(__MACH__) && defined(__APPLE__)
#	define LIBRADIAL_PLATFORM LIBRADIAL_LINUX
#	define LIBRADIAL_UNIXLIKE true
#	ifdef __GNUC__
#		define LIBRADIAL_COMPILER LIBRADIAL_GCC
#	endif
#	ifdef __LP64__
#		define LIBRADIAL_PLATFORM32 false
#	else
#		define LIBRADIAL_PLATFORM32 true
#	endif

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#	define LIBRADIAL_PLATFORM LIBRADIAL_BSD
#	define LIBRADIAL_UNIXLIKE true
#	ifdef __GNUC__
#		define LIBRADIAL_COMPILER LIBRADIAL_GCC
#	endif
#	ifdef __LP64__
#		define LIBRADIAL_PLATFORM32 false
#	else
#		define LIBRADIAL_PLATFORM32 true
#	endif 

#endif

#ifndef LIBRADIAL_COMPILER
#	ifdef __clang__
#		define LIBRADIAL_COMPILER LIBRADIAL_CLANG

#	elif defined(_MSC_VER)
#		define LIBRADIAL_COMPILER LIBRADIAL_MSVC

#	elif defined(__EMSCRIPTEN__) || defined(__wasm__) || defined(__wasm32__)
#		define LIBRADIAL_COMPILER LIBRADIAL_EMSCRIPTEN

#	endif
#endif


#if LIBRADIAL_COMPILER == LIBRADIAL_MSVC
#	define LRAD_API __declspec(dllexport)
#else
#	define LRAD_API
#endif



#endif // _LIBRADIAL__PLATFORM_H_
