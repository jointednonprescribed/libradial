
#ifndef _LIBRADIAL__PLATFORM_H_
#define _LIBRADIAL__PLATFORM_H_

#include "config.h"



/* Platform Selection Macros */
#define LIBRADIAL_LINUX            1
#define LIBRADIAL_WINDOWS          2
#define LIBRADIAL_OSX              3
#define LIBRADIAL_BSD              4
#define LIBRADIAL_WASM             5
/* Compiler Selection Macros */
#define LIBRADIAL_GCC              6
#define LIBRADIAL_MSVC             7
#define LIBRADIAL_CLANG            8
#define LIBRADIAL_EMSCRIPTEN       9
#define LIBRADIAL_UNKNOWN_PLATFORM 0


#ifndef LIBRADIAL_PLATFORM
/* Detect Windows Platforms */
#	ifdef _WIN32
#		define LIBRADIAL_PLATFORM LIBRADIAL_WINDOWS
#		define LIBRADIAL_UNIXLIKE false
#		ifdef _WIN64
#			define LIBRADIAL_PLATFORM32 false
#		else
#			define LIBRADIAL_PLATFORM32 true
#		endif

/* Detect Linux Platforms */
#	elif defined(__linux) || defined(__linux__) || defined(__gnu_linux__)
#		define LIBRADIAL_PLATFORM LIBRADIAL_LINUX
#		define LIBRADIAL_UNIXLIKE true
#		ifdef __LP64__
#			define LIBRADIAL_PLATFORM32 false
#		else
#			define LIBRADIAL_PLATFORM32 true
#		endif

/* Detect BSD Platforms */
#	elif defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
#		define LIBRADIAL_PLATFORM LIBRADIAL_BSD
#		define LIBRADIAL_UNIXLIKE true
#		ifdef __LP64__
#			define LIBRADIAL_PLATFORM32 false
#		else
#			define LIBRADIAL_PLATFORM32 true
#		endif

/* Detect OSX */
#	elif defined(__APPLE__) && defined(__MACH__)
#		define LIBRADIAL_PLATFORM LIBRADIAL_OSX
#		define LIBRADIAL_UNIXLIKE true
#		ifdef __LP64__
#			define LIBRADIAL_PLATFORM32 false
#		else
#			define LIBRADIAL_PLATFORM32 true
#		endif

/* Detect WebAssembly (Emscripten) Compilation Environment */
#	elif defined(__EMSCRIPTEN__) || defined(__wasm__) || defined(__wabi__)
#		define LIBRADIAL_PLATFORM   LIBRADIAL_WASM
#		define LIBRADIAL_UNIXLIKE   false
#		define LIBRADIAL_PLATFORM32 true
#	    define LIBRADIAL_COMPILER   LIBRADIAL_EMSCRIPTEN

#	else
#		error "Couldn't automatically detect the platform, please specify it using one of the platform selection macros in libradial/platform.h as the value for the macro: LIBRADIAL_PLATFORM."
#	endif
#endif


#if LIBRADIAL_PLATFORM == LIBRADIAL_WINDOWS
#	define LRAD_API __declspec(dllexport)
#else
#	define LRAD_API
#endif



#endif // _LIBRADIAL__PLATFORM_H_
