
#include <libradial.h>


lrad_vec2  lrad_vec2_plus(lrad_vec2 self, lrad_vec2 other)
{
	return (lrad_vec2) { .x = self.x + other.x, .y = self.y + other.y };
}
lrad_vec2* lrad_vec2_add(lrad_vec2 *self, lrad_vec2 other)
{
	if (self != NULL) {
		self->x += other.x;
		self->y += other.y;
	}

	return self;
}
lrad_vec2  lrad_vec2_minus(lrad_vec2 self, lrad_vec2 other)
{
	return (lrad_vec2) { .x = self.x - other.x, .y = self.y - other.y };
}
lrad_vec2* lrad_vec2_sub(lrad_vec2 *self, lrad_vec2 other)
{
	if (self != NULL) {
		self->x -= other.x;
		self->y -= other.y;
	}

	return self;
}
lrad_vec2  lrad_vec2_negative(lrad_vec2 self)
{
	return (lrad_vec2) { .x = -self.x, .y = -self.y };
}
lrad_vec2* lrad_vec2_negate(lrad_vec2 *self)
{
	if (self != NULL) {
		self->x = -(self->x);
		self->y = -(self->y);
	}

	return self;
}
lrad_vec2  lrad_vec2_times(lrad_vec2 self, double other)
{
	return (lrad_vec2) { .x = self.x * other, .y = self.y * other };
}
lrad_vec2* lrad_vec2_mult(lrad_vec2 *self, double other)
{
	if (self != NULL) {
		self->x *= other;
		self->y *= other;
	}

	return self;
}
lrad_vec2  lrad_vec2_over(lrad_vec2 self, double other)
{
	return (lrad_vec2) { .x = self.x / other, .y = self.y / other };
}
lrad_vec2* lrad_vec2_div(lrad_vec2 *self, double other)
{
	if (self != NULL) {
		self->x /= other;
		self->y /= other;
	}

	return self;
}
double  lrad_vec2_dot(lrad_vec2 self, lrad_vec2 other)
{
	return ((self.x * other.x) + (self.x * other.y) + (self.y * other.x) + (self.y * other.y));
}
double  lrad_vec2_det(lrad_vec2 self, lrad_vec2 other)
{
	const double
		self_angle    = atan2(self.y, self.x),
		other_angle   = atan2(self.y, self.x),
		self_mag      = sqrt((self.x * self.x) + (self.y * self.y)),
		other_mag     = sqrt((other.x * other.x) + (other.y * other.y)),

		angle_between = self_angle - other_angle,
		cross_normal  = (double) (((char) (angle_between > .0)) - ((char) (angle_between < .0)));

	return self_mag * other_mag * sin(angle_between) * cross_normal;
}
lrad_vec2  lrad_vec2_had(lrad_vec2 self, lrad_vec2 other)
{
	return (lrad_vec2) { .x = self.x * other.x, .y = self.y * other.y };
}
lrad_vec2* lrad_vec2_shad(lrad_vec2 *self, lrad_vec2 other)
{
	if (self != NULL) {
		self->x *= other.x;
		self->y *= other.y;
	}

	return self;
}
int        lrad_vec2_mcmp(lrad_vec2 cmp1, lrad_vec2 cmp2)
{
	double sqsum1 = (cmp1.x * cmp1.x) + (cmp1.y * cmp1.y), sqsum2 = (cmp2.x * cmp2.x) + (cmp2.y * cmp2.y);

	return (int) (((char) (sqsum1 > sqsum2)) - ((char) (sqsum1 < sqsum2)));
}
bool       lrad_vec2_eq(lrad_vec2 cmp1, lrad_vec2 cmp2)
{
	return cmp1.x == cmp2.x && cmp1.y == cmp2.y;
}
bool       lrad_vec2_ne(lrad_vec2 cmp1, lrad_vec2 cmp2)
{
	return cmp1.x != cmp2.x || cmp1.y != cmp2.y;
}
double     lrad_vec2_mag(lrad_vec2 self)
{
	return sqrt((self.x * self.x) + (self.y * self.y));
}
lrad_vec2  lrad_vec2_norm(lrad_vec2 self)
{
	const double phase = atan2(self.y, self.x);

	return (lrad_vec2) {cos(phase), sin(phase)};
}
lrad_vec2* lrad_vec2_snorm(lrad_vec2 *self)
{
	if (self != NULL) {
		const double phase = atan2(self->y, self->x);

		self->x = cos(phase);
		self->y = sin(phase);
	}

	return self;
}
double     lrad_vec2_phase(lrad_vec2 self)
{
	return atan2(self.y, self.x);
}

lrad_fvec2  lrad_fvec2_plus(lrad_fvec2 self, lrad_fvec2 other)
{
	return (lrad_vec2) { .x = self.x + other.x, .y = self.y + other.y };
}
lrad_fvec2* lrad_fvec2_add(lrad_fvec2 *self, lrad_fvec2 other)
{
	if (self != NULL) {
		self->x += other.x;
		self->y += other.y;
	}

	return self;
}
lrad_fvec2  lrad_fvec2_minus(lrad_fvec2 self, lrad_fvec2 other)
{
	return (lrad_vec2) { .x = self.x - other.x, .y = self.y - other.y };
}
lrad_fvec2* lrad_fvec2_sub(lrad_fvec2 *self, lrad_fvec2 other)
{
	if (self != NULL) {
		self->x -= other.x;
		self->y -= other.y;
	}

	return self;
}
lrad_fvec2  lrad_fvec2_negative(lrad_fvec2 self)
{
	return (lrad_vec2) { .x = -self.x, .y = -self.y };
}
lrad_fvec2* lrad_fvec2_negate(lrad_fvec2 *self)
{
	if (self != NULL) {
		self->x = -(self->x);
		self->y = -(self->y);
	}

	return self;
}
lrad_fvec2  lrad_fvec2_times(lrad_fvec2 self, float other)
{
	return (lrad_vec2) { .x = self.x * other, .y = self.y * other };
}
lrad_fvec2* lrad_fvec2_mult(lrad_fvec2 *self, float other)
{
	if (self != NULL) {
		self->x *= other;
		self->y *= other;
	}

	return self;
}
lrad_fvec2  lrad_fvec2_over(lrad_fvec2 self, float other)
{
	return (lrad_vec2) { .x = self.x / other, .y = self.y / other };
}
lrad_fvec2* lrad_fvec2_div(lrad_fvec2 *self, float other)
{
	if (self != NULL) {
		self->x /= other;
		self->y /= other;
	}

	return self;
}
float       lrad_fvec2_dot(lrad_fvec2 self, lrad_fvec2 other)
{
	return ((self.x * other.x) + (self.x * other.y) + (self.y * other.x) + (self.y * other.y));
}
float       lrad_fvec2_det(lrad_fvec2 self, lrad_fvec2 other)
{
	const float
		self_angle    = atan2(self.y, self.x),
		other_angle   = atan2(self.y, self.x),
		self_mag      = sqrt((self.x * self.x) + (self.y * self.y)),
		other_mag     = sqrt((other.x * other.x) + (other.y * other.y)),

		angle_between = self_angle - other_angle,
		cross_normal  = (float) (((char) (angle_between > .0)) - ((char) (angle_between < .0)));

	return self_mag * other_mag * sin(angle_between) * cross_normal;
}
lrad_fvec2  lrad_fvec2_had(lrad_fvec2 self, lrad_fvec2 other)
{
	return (lrad_vec2) { .x = self.x * other.x, .y = self.y * other.y };
}
lrad_fvec2* lrad_fvec2_shad(lrad_fvec2 *self, lrad_fvec2 other)
{
	if (self != NULL) {
		self->x *= other.x;
		self->y *= other.y;
	}

	return self;
}
int         lrad_fvec2_mcmp(lrad_fvec2 cmp1, lrad_fvec2 cmp2)
{
	float sqsum1 = (cmp1.x * cmp1.x) + (cmp1.y * cmp1.y), sqsum2 = (cmp2.x * cmp2.x) + (cmp2.y * cmp2.y);

	return (int) (((char) (sqsum1 > sqsum2)) - ((char) (sqsum1 < sqsum2)));
}
bool        lrad_fvec2_eq(lrad_fvec2 cmp1, lrad_fvec2 cmp2)
{
	return cmp1.x == cmp2.x && cmp1.y == cmp2.y;
}
bool        lrad_fvec2_ne(lrad_fvec2 cmp1, lrad_fvec2 cmp2)
{
	return cmp1.x != cmp2.x || cmp1.y != cmp2.y;
}
float       lrad_fvec2_mag(lrad_fvec2 self)
{
	return sqrt((self.x * self.x) + (self.y * self.y));
}
lrad_fvec2  lrad_fvec2_norm(lrad_fvec2 self)
{
	const float phase = atan2(self.y, self.x);

	return (lrad_fvec2) {cos(phase), sin(phase)};
}
lrad_fvec2* lrad_fvec2_snorm(lrad_fvec2 *self)
{
	if (self != NULL) {
		const float phase = atan2(self->y, self->x);

		self->x = cos(phase);
		self->y = sin(phase);
	}

	return self;
}
float       lrad_fvec2_phase(lrad_fvec2 self)
{
	return atan2(self.y, self.x);
}


lrad_vec3  lrad_vec3_plus(const lrad_vec3 *self, const lrad_vec3 *other)
{
	return (lrad_vec3) { .x = self.x + other.x, .y = self.y + other.y, .z = self.z + other.z };
}
lrad_vec3* lrad_vec3_add(lrad_vec3 *self, const lrad_vec3 *other)
{
	if (self != NULL) {
		self->x += other.x;
		self->y += other.y;
		self->z += other.z;
	}

	return self;
}
lrad_vec3  lrad_vec3_minus(const lrad_vec3 *self, const lrad_vec3 *other)
{
	return (lrad_vec3) { .x = self.x - other.x, .y = self.y - other.y, .z = self.z - other.z };
}
lrad_vec3* lrad_vec3_sub(lrad_vec3 *self, const lrad_vec3 *other)
{
	if (self != NULL) {
		self->x -= other.x;
		self->y -= other.y;
		self->z -= other.z;
	}

	return self;
}
lrad_vec3  lrad_vec3_negative(const lrad_vec3 *self)
{
	return (lrad_vec3) { .x = -self.x, .y = -self.y, .z = -self.z };
}
lrad_vec3* lrad_vec3_negate(lrad_vec3 *self)
{
	if (self != NULL) {
		self->x = -(self->x);
		self->y = -(self->y);
		self->z = -(self->z);
	}

	return self;
}
lrad_vec3  lrad_vec3_times(const lrad_vec3 *self, double other)
{
	return (lrad_vec3) { .x = self.x * other, .y = self.y * other, .z = self.z * other };
}
lrad_vec3* lrad_vec3_mult(lrad_vec3 *self, double other)
{
	if (self != NULL) {
		self->x *= other;
		self->y *= other;
		self->z *= other;
	}

	return self;
}
lrad_vec3  lrad_vec3_over(const lrad_vec3 *self, double other)
{
	if (self != NULL)
		return (lrad_vec3) { .x = self.x / other, .y = self.y / other, .z = self.z / other };
	else {
		lrad_throw("NullPointerError", "Null pointer in lrad_vec2_over().", -1);
		return NAN;
	}
}
lrad_vec3* lrad_vec3_div(lrad_vec3 *self, double other)
{
	if (self != NULL) {
		self->x /= other;
		self->y /= other;
		self->z /= other;
	}

	return self;
}
double  lrad_vec3_dot(const lrad_vec3 *self, const lrad_vec3 *other)
{
	if (self != NULL && other != NULL)
		return (
				(self.x * other.x) + (self.x * other.y) + (self.x * other.z) +
				(self.y * other.x) + (self.y * other.y) + (self.y * other.z) +
				(self.z * other.x) + (self.z * other.y) + (self.z * other.z)
				);
	else {
		lrad_throw("NullPointerError", "Null pointer in lrad_vec2_dot().", -1);
		return NAN;
	}
}
double  lrad_vec3_det(lrad_vec3 *self, lrad_vec3 *other)
{
	const double
		self_angle    = atan2(self.y, self.x),
		other_angle   = atan2(self.y, self.x),
		self_mag      = sqrt((self.x * self.x) + (self.y * self.y)),
		other_mag     = sqrt((other.x * other.x) + (other.y * other.y)),

		angle_between = self_angle - other_angle,
		cross_normal  = (double) (((char) (angle_between > .0)) - ((char) (angle_between < .0)));

	return self_mag * other_mag * sin(angle_between) * cross_normal;
}
lrad_vec3  lrad_vec3_had(lrad_vec3 *self, lrad_vec3 *other)
{
	return (lrad_vec3) { .x = self.x * other.x, .y = self.y * other.y };
}
lrad_vec3* lrad_vec3_shad(lrad_vec3 *self, lrad_vec3 *other)
{
	if (self != NULL) {
		self->x *= other.x;
		self->y *= other.y;
	}

	return self;
}
int        lrad_vec3_mcmp(lrad_vec3 *cmp1, lrad_vec3 *cmp2)
{
	double sqsum1 = (cmp1.x * cmp1.x) + (cmp1.y * cmp1.y), sqsum2 = (cmp2.x * cmp2.x) + (cmp2.y * cmp2.y);

	return (int) (((char) (sqsum1 > sqsum2)) - ((char) (sqsum1 < sqsum2)));
}
bool       lrad_vec3_eq(lrad_vec3 *cmp1, lrad_vec3 *cmp2)
{
	return cmp1.x == cmp2.x && cmp1.y == cmp2.y;
}
bool       lrad_vec3_ne(lrad_vec3 *cmp1, lrad_vec3 *cmp2)
{
	return cmp1.x != cmp2.x || cmp1.y != cmp2.y;
}
double     lrad_vec3_mag(lrad_vec3 *self)
{
	return sqrt((self.x * self.x) + (self.y * self.y));
}
double     lrad_vec3_phase(lrad_vec3 *self)
{
	return atan2(self.y, self.x);
}

lrad_fvec3  lrad_fvec3_plus(lrad_fvec3 self, lrad_fvec3 other)
{
	return (lrad_vec3) { .x = self.x + other.x, .y = self.y + other.y };
}
lrad_fvec3* lrad_fvec3_add(lrad_fvec3 *self, lrad_fvec3 other)
{
	if (self != NULL) {
		self->x += other.x;
		self->y += other.y;
	}

	return self;
}
lrad_fvec3  lrad_fvec3_minus(lrad_fvec3 self, lrad_fvec3 other)
{
	return (lrad_vec3) { .x = self.x - other.x, .y = self.y - other.y };
}
lrad_fvec3* lrad_fvec3_sub(lrad_fvec3 *self, lrad_fvec3 other)
{
	if (self != NULL) {
		self->x -= other.x;
		self->y -= other.y;
	}

	return self;
}
lrad_fvec3  lrad_fvec3_negative(lrad_fvec3 self)
{
	return (lrad_vec3) { .x = -self.x, .y = -self.y };
}
lrad_fvec3* lrad_fvec3_negate(lrad_fvec3 *self)
{
	if (self != NULL) {
		self->x = -(self->x);
		self->y = -(self->y);
	}

	return self;
}
lrad_fvec3  lrad_fvec3_times(lrad_fvec3 self, float other)
{
	return (lrad_vec3) { .x = self.x * other, .y = self.y * other };
}
lrad_fvec3* lrad_fvec3_mult(lrad_fvec3 *self, float other)
{
	if (self != NULL) {
		self->x *= other;
		self->y *= other;
	}

	return self;
}
lrad_fvec3  lrad_fvec3_over(lrad_fvec3 self, float other)
{
	return (lrad_vec3) { .x = self.x / other, .y = self.y / other };
}
lrad_fvec3* lrad_fvec3_div(lrad_fvec3 *self, float other)
{
	if (self != NULL) {
		self->x /= other;
		self->y /= other;
	}

	return self;
}
float       lrad_fvec3_dot(lrad_fvec3 self, lrad_fvec3 other)
{
	return ((self.x * other.x) + (self.x * other.y) + (self.y * other.x) + (self.y * other.y));
}
float       lrad_fvec3_det(lrad_fvec3 self, lrad_fvec3 other)
{
	const float
		self_angle    = atan2(self.y, self.x),
		other_angle   = atan2(self.y, self.x),
		self_mag      = sqrt((self.x * self.x) + (self.y * self.y)),
		other_mag     = sqrt((other.x * other.x) + (other.y * other.y)),

		angle_between = self_angle - other_angle,
		cross_normal  = (float) (((char) (angle_between > .0)) - ((char) (angle_between < .0)));

	return self_mag * other_mag * sin(angle_between) * cross_normal;
}
lrad_fvec3  lrad_fvec3_had(lrad_fvec3 self, lrad_fvec3 other)
{
	return (lrad_vec3) { .x = self.x * other.x, .y = self.y * other.y };
}
lrad_fvec3* lrad_fvec3_shad(lrad_fvec3 *self, lrad_fvec3 other)
{
	if (self != NULL) {
		self->x *= other.x;
		self->y *= other.y;
	}

	return self;
}
int         lrad_fvec3_mcmp(lrad_fvec3 cmp1, lrad_fvec3 cmp2)
{
	float sqsum1 = (cmp1.x * cmp1.x) + (cmp1.y * cmp1.y), sqsum2 = (cmp2.x * cmp2.x) + (cmp2.y * cmp2.y);

	return (int) (((char) (sqsum1 > sqsum2)) - ((char) (sqsum1 < sqsum2)));
}
bool        lrad_fvec3_eq(lrad_fvec3 cmp1, lrad_fvec3 cmp2)
{
	return cmp1.x == cmp2.x && cmp1.y == cmp2.y;
}
bool        lrad_fvec3_ne(lrad_fvec3 cmp1, lrad_fvec3 cmp2)
{
	return cmp1.x != cmp2.x || cmp1.y != cmp2.y;
}
float       lrad_fvec3_mag(lrad_fvec3 self)
{
	return sqrt((self.x * self.x) + (self.y * self.y));
}
float       lrad_fvec3_phase(lrad_fvec3 self)
{
	return atan2(self.y, self.x);
}
