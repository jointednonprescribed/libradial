
#ifndef _LIBRADIAL__types_COMPLEX_H_
#define _LIBRADIAL__types_COMPLEX_H_ 1

#include "../includes.h"

LRAD_EXTERN_C



typedef struct {
	double re, im;
} lrad_complex;

#define LRAD_I       ((lrad_complex){.0, 1.0})
#define LRAD_MINUS_I ((lrad_complex){.0, -1.0})
#define LRAD_1_I     ((lrad_complex){.0, -1.0})



LRAD_END_EXTERN_C

#endif // _LIBRADIAL__types_COMPLEX_H_
