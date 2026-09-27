
#ifndef _LIBRADIAL__SYSAPI_H_
#define _LIBRADIAL__SYSAPI_H_ 1

#include "includes.h"



void* _lrad_malloc(size_t size);
void* _lrad_realloc(void *ptr, size_t size);
void* _lrad_use_ptr(void *ptr);
void* _lrad_copy(void *ptr);
void* _lrad_drop(void *ptr);



#endif // _LIBRADIAL__SYSAPI_H_
