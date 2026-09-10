
#ifndef _LIBRADIAL__types_VEC_H_
#define _LIBRADIAL__types_VEC_H_ 1

#include "../includes.h"



typedef struct {
	double x, y;
} lrad_dvec2, lrad_vec2;

lrad_vec2  lrad_vec2_plus(lrad_vec2 self, lrad_vec2 other);
lrad_vec2* lrad_vec2_add(lrad_vec2 *self, lrad_vec2 other);
lrad_vec2  lrad_vec2_minus(lrad_vec2 self, lrad_vec2 other);
lrad_vec2* lrad_vec2_sub(lrad_vec2 *self, lrad_vec2 other);
lrad_vec2  lrad_vec2_negative(lrad_vec2 self);
lrad_vec2* lrad_vec2_negate(lrad_vec2 *self);
lrad_vec2  lrad_vec2_times(lrad_vec2 self, double other);
lrad_vec2* lrad_vec2_mult(lrad_vec2 *self, double other);
lrad_vec2  lrad_vec2_over(lrad_vec2 self, double other);
lrad_vec2* lrad_vec2_div(lrad_vec2 *self, double other);
double     lrad_vec2_dot(lrad_vec2 self, lrad_vec2 other);
double     lrad_vec2_det(lrad_vec2 self, lrad_vec2 other);
lrad_vec2  lrad_vec2_had(lrad_vec2 self, lrad_vec2 other);
lrad_vec2* lrad_vec2_shad(lrad_vec2 *self, lrad_vec2 other);
int        lrad_vec2_mcmp(lrad_vec2 cmp1, lrad_vec2 cmp2);
bool       lrad_vec2_eq(lrad_vec2 cmp1, lrad_vec2 cmp2);
bool       lrad_vec2_ne(lrad_vec2 cmp1, lrad_vec2 cmp2);
double     lrad_vec2_mag(lrad_vec2 self);
lrad_vec2  lrad_vec2_norm(lrad_vec2 self);
lrad_vec2* lrad_vec2_snorm(lrad_vec2 *self);
double     lrad_vec2_phase(lrad_vec2 self);


typedef struct {
	float x, y;
} lrad_fvec2;

lrad_fvec2  lrad_fvec2_plus(lrad_fvec2 self, lrad_fvec2 other);
lrad_fvec2* lrad_fvec2_add(lrad_fvec2 *self, lrad_fvec2 other);
lrad_fvec2  lrad_fvec2_minus(lrad_fvec2 self, lrad_fvec2 other);
lrad_fvec2* lrad_fvec2_sub(lrad_fvec2 *self, lrad_fvec2 other);
lrad_fvec2  lrad_fvec2_negative(lrad_fvec2 self);
lrad_fvec2* lrad_fvec2_negate(lrad_fvec2 *self);
lrad_fvec2  lrad_fvec2_times(lrad_fvec2 self, float other);
lrad_fvec2* lrad_fvec2_mult(lrad_fvec2 *self, float other);
lrad_fvec2  lrad_fvec2_over(lrad_fvec2 self, float other);
lrad_fvec2* lrad_fvec2_div(lrad_fvec2 *self, float other);
float       lrad_fvec2_dot(lrad_fvec2 self, lrad_fvec2 other);
lrad_fvec2  lrad_fvec2_had(lrad_fvec2 self, lrad_fvec2 other);
lrad_fvec2* lrad_fvec2_shad(lrad_fvec2 *self, lrad_fvec2 other);
int         lrad_fvec2_mcmp(lrad_fvec2 cmp1, lrad_fvec2 cmp2);
bool        lrad_fvec2_eq(lrad_fvec2 cmp1, lrad_fvec2 cmp2);
bool        lrad_fvec2_ne(lrad_fvec2 cmp1, lrad_fvec2 cmp2);
float       lrad_fvec2_mag(lrad_fvec2 self);
lrad_fvec2  lrad_fvec2_norm(lrad_fvec2 self);
lrad_fvec2* lrad_fvec2_snorm(lrad_fvec2 *self);
float       lrad_fvec2_phase(lrad_fvec2 self);

#define lrad_vec2_from_fvec2(fvec3) (lrad_vec2){(double)(fvec2).x, (double)(fvec2).y, (double)(fvec2).z}
#define lrad_fvec2_from_vec2(vec3) (lrad_fvec2){(float)(vec2).x, (float)(vec2).y, (float)(vec2).z}


typedef struct {
	double x, y, z;
} lrad_dvec3, lrad_vec3;

lrad_vec3  lrad_vec3_plus(const lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3* lrad_vec3_add(lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3  lrad_vec3_minus(const lrad_vec3 self, const lrad_vec3 *other);
lrad_vec3* lrad_vec3_sub(lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3  lrad_vec3_negative(const lrad_vec3 *self);
lrad_vec3* lrad_vec3_negate(lrad_vec3 *self);
lrad_vec3  lrad_vec3_times(const lrad_vec3 *self, double other);
lrad_vec3* lrad_vec3_mult(lrad_vec3 *self, double other);
lrad_vec3  lrad_vec3_over(const lrad_vec3 *self, double other);
lrad_vec3* lrad_vec3_div(lrad_vec3 *self, double other);
double     lrad_vec3_dot(const lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3  lrad_vec3_cross(const lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3* lrad_vec3_scross(lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3  lrad_vec3_had(const lrad_vec3 *self, const lrad_vec3 *other);
lrad_vec3* lrad_vec3_shad(const lrad_vec3 *self, const lrad_vec3 *other);
int        lrad_vec3_mcmp(const lrad_vec3 *cmp1, const lrad_vec3 *cmp2);
bool       lrad_vec3_eq(const lrad_vec3 *cmp1, const lrad_vec3 *cmp2);
bool       lrad_vec3_ne(const lrad_vec3 *cmp1, const lrad_vec3 *cmp2);
double     lrad_vec3_mag(const lrad_vec3 *self);
lrad_vec3  lrad_vec3_norm(const lrad_vec3 *self);
lrad_vec3* lrad_vec3_snorm(lrad_vec3 *self);
double     lrad_vec3_phasexy(const lrad_vec3 *self);
double     lrad_vec3_phasexz(const lrad_vec3 *self);
double     lrad_vec3_phaseyz(const lrad_vec3 *self);


typedef struct {
	float x, y, z;
} lrad_fvec3;

lrad_fvec3  lrad_fvec3_plus(lrad_fvec3 self, lrad_fvec3 other);
lrad_fvec3* lrad_fvec3_add(lrad_fvec3 *self, lrad_fvec3 other);
lrad_fvec3  lrad_fvec3_minus(lrad_fvec3 self, lrad_fvec3 other);
lrad_fvec3* lrad_fvec3_sub(lrad_fvec3 *self, lrad_fvec3 other);
lrad_fvec3  lrad_fvec3_negative(lrad_fvec3 self);
lrad_fvec3* lrad_fvec3_negate(lrad_fvec3 *self);
lrad_fvec3  lrad_fvec3_times(lrad_fvec3 self, float other);
lrad_fvec3* lrad_fvec3_mult(lrad_fvec3 *self, float other);
lrad_fvec3  lrad_fvec3_over(lrad_fvec3 self, float other);
lrad_fvec3* lrad_fvec3_div(lrad_fvec3 *self, float other);
float       lrad_fvec3_dot(lrad_fvec3 self, lrad_fvec3 other);
float       lrad_fvec3_det(lrad_fvec3 self, lrad_fvec3 other);
lrad_fvec3  lrad_fvec3_had(lrad_fvec3 self, lrad_fvec3 other);
lrad_fvec3* lrad_fvec3_shad(lrad_fvec3 *self, lrad_fvec3 other);
int         lrad_fvec3_cmp(lrad_fvec3 cmp1, lrad_fvec3 cmp2);
bool        lrad_fvec3_eq(lrad_fvec3 cmp1, lrad_fvec3 cmp2);
bool        lrad_fvec3_ne(lrad_fvec3 cmp1, lrad_fvec3 cmp2);
float       lrad_fvec3_mag(lrad_fvec3 self);
lrad_fvec3  lrad_fvec3_norm(const lrad_fvec3 *self);
lrad_fvec3* lrad_fvec3_snorm(lrad_fvec3 *self);
float       lrad_fvec3_phasexy(lrad_fvec3 *self);
float       lrad_fvec3_phasexz(lrad_fvec3 *self);
float       lrad_fvec3_phaseyz(lrad_fvec3 *self);

#define lrad_vec3_from_fvec3(fvec3) (lrad_vec3){(double)(fvec3).x, (double)(fvec3).y, (double)(fvec3).z}
#define lrad_fvec3_from_vec3(vec3) (lrad_fvec3){(float)(vec3).x, (float)(vec3).y, (float)(vec3).z}

#define lrad_vec3_from_vec2(vec2) (lrad_vec3){(vec2).x, (vec2).y, .0}
#define lrad_fvec3_from_vec2(vec2) (lrad_fvec3){(vec2).x, (vec2).y, .0}
#define lrad_vec3_from_vec2_1(vec2) (lrad_vec3){(vec2).x, (vec2).y, 1.0}
#define lrad_fvec3_from_vec2_1(vec2) (lrad_fvec3){(vec2).x, (vec2).y, 1.0}


typedef struct {
	double x, y, z, w;
} lrad_dvec4, lrad_vec4;

lrad_vec4  lrad_vec4_plus(lrad_vec4 *self, lrad_vec4 *other);
lrad_vec4* lrad_vec4_add(lrad_vec4 *self, lrad_vec4 *other);
lrad_vec4  lrad_vec4_minus(lrad_vec4 self, lrad_vec4 *other);
lrad_vec4* lrad_vec4_sub(lrad_vec4 *self, lrad_vec4 *other);
lrad_vec4  lrad_vec4_negative(lrad_vec4 *self);
lrad_vec4* lrad_vec4_negate(lrad_vec4 *self);
lrad_vec4  lrad_vec4_times(lrad_vec4 *self, double other);
lrad_vec4* lrad_vec4_mult(lrad_vec4 *self, double other);
lrad_vec4  lrad_vec4_over(lrad_vec4 *self, double other);
lrad_vec4* lrad_vec4_div(lrad_vec4 *self, double other);
double     lrad_vec4_dot(lrad_vec4 *self, lrad_vec4 *other);
double     lrad_vec4_det(lrad_vec4 *self, lrad_vec4 *other);
lrad_vec4  lrad_vec4_had(lrad_vec4 *self, lrad_vec4 *other);
lrad_vec4* lrad_vec4_shad(lrad_vec4 *self, lrad_vec4 *other);
int        lrad_vec4_mcmp(lrad_vec4 *cmp1, lrad_vec4 *cmp2);
bool       lrad_vec4_eq(lrad_vec4 *cmp1, lrad_vec4 *cmp2);
bool       lrad_vec4_ne(lrad_vec4 *cmp1, lrad_vec4 *cmp2);
double     lrad_vec4_mag(lrad_vec4 *self);
double     lrad_vec4_phase(lrad_vec4 *self);


typedef struct {
	float x, y, z, w;
} lrad_fvec4;

lrad_fvec4  lrad_fvec4_plus(lrad_fvec4 *self, lrad_fvec4 *other);
lrad_fvec4* lrad_fvec4_add(lrad_fvec4 *self, lrad_fvec4 *other);
lrad_fvec4  lrad_fvec4_minus(lrad_fvec4 self, lrad_fvec4 *other);
lrad_fvec4* lrad_fvec4_sub(lrad_fvec4 *self, lrad_fvec4 *other);
lrad_fvec4  lrad_fvec4_negative(lrad_fvec4 *self);
lrad_fvec4* lrad_fvec4_negate(lrad_fvec4 *self);
lrad_fvec4  lrad_fvec4_times(lrad_fvec4 *self, float other);
lrad_fvec4* lrad_fvec4_mult(lrad_fvec4 *self, float other);
lrad_fvec4  lrad_fvec4_over(lrad_fvec4 *self, float other);
lrad_fvec4* lrad_fvec4_div(lrad_fvec4 *self, float other);
float       lrad_fvec4_dot(lrad_fvec4 *self, lrad_fvec4 *other);
float       lrad_fvec4_det(lrad_fvec4 *self, lrad_fvec4 *other);
lrad_fvec4  lrad_fvec4_had(lrad_fvec4 *self, lrad_fvec4 *other);
lrad_fvec4* lrad_fvec4_shad(lrad_fvec4 *self, lrad_fvec4 *other);
int         lrad_fvec4_mcmp(lrad_fvec4 *cmp1, lrad_fvec4 *cmp2);
bool        lrad_fvec4_eq(lrad_fvec4 *cmp1, lrad_fvec4 *cmp2);
bool        lrad_fvec4_ne(lrad_fvec4 *cmp1, lrad_fvec4 *cmp2);
float       lrad_fvec4_mag(lrad_fvec4 *self);


/* By default, 3D and 4D vectors use the following scheme for naming different angles:
 * "Vertical Y":
 *  - Yaw: An angle on the plane formed by the X and Z axes (lrad_vec2_phasexz).
 *  - Pitch: An angle on the plane formed by the X and Y axes, which is equal to
 *           the angle formed between the Y and Z axes (lrad_[f]vec2_phasexy or
 *           lrad_[f]vec2_phaseyz).
 * By defining the macro LIBRADIAL_VEC_USE_VERTICAL_Z to use the following scheme
 * instead:
 * "Vertical Z":
 *  - Yaw: An angle on the plane formed by the X and Y axes (lrad_[f]vec3_phasexy).
 *  - Pitch: An angle on the plane formed by the X and Z axes, which is equal to
 *           the angle formed between the Y and Z axes (lrad_[f]vec3_phasexz or
 *           lrad_[f]vec3_phaseyz).
 */
#ifdef LIBRADIAL_VEC_USE_VERTICAL_Z
#	define lrad_vec3_yaw    lrad_vec3_phasexy
#	define lrad_fvec3_yaw   lrad_fvec3_phasexy
#	define lrad_vec3_pitch  lrad_vec3_phasexz
#	define lrad_fvec3_pitch lrad_fvec3_phasexz
#	define lrad_vec4_yaw    lrad_vec4_phasexy
#	define lrad_fvec4_yaw   lrad_fvec4_phasexy
#	define lrad_vec4_pitch  lrad_vec4_phasexz
#	define lrad_fvec4_pitch lrad_fvec4_phasexz
#else
#	define lrad_vec3_yaw    lrad_vec3_phasexz
#	define lrad_fvec3_yaw   lrad_fvec3_phasexz
#	define lrad_vec3_pitch  lrad_vec3_phasexy
#	define lrad_fvec3_pitch lrad_fvec3_phasexy
#	define lrad_vec4_yaw    lrad_vec4_phasexz
#	define lrad_fvec4_yaw   lrad_fvec4_phasexz
#	define lrad_vec4_pitch  lrad_vec4_phasexy
#	define lrad_fvec4_pitch lrad_fvec4_phasexy
#endif



#endif // _LIBRADIAL__SYSAPI_H_
