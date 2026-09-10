
#ifndef _LIBRADIAL__INCLUDES_H_
#define _LIBRADIAL__INCLUDES_H_ 1

#ifndef _LIBRADIAL__PLATFORM_H_
#	include "platform.h"
#endif



/* C/C++ Standard Library Includes */
#if LIBRADIAL_NO_CXX == 0
#	include <cstddef>
#	include <cstdlib>
#	include <cstdio>
#	include <cstdint>
#	include <cstring>
#	include <cmath>
#	include <climits>
#	include <cfloat>
#	include <ctime>

#	include <vector>
#	include <string>
#	include <utility>
#	include <exception>
#else
#	include <stdbool.h>
#	include <stddef.h>
#	include <stdlib.h>
#	include <stdio.h>
#	include <stdint.h>
#	include <string.h>
#	include <math.h>
#	include <limits.h>
#	include <float.h>
#	include <time.h>
#endif



#endif // _LIBRADIAL__INCLUDES_H_
