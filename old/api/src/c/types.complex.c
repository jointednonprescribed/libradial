
#ifndef _LIBRADIAL_
#	include <libradial.h>
#endif




LRAD_API lradComplex* lradCAssign(lradComplex *a, lradComplex b)
{
	if (a == NULL)
		return NULL;

	a->real = b.real;
	a->imag = b.imag;

	return a;
}
LRAD_API lradComplex* lradCAssignR(lradComplex *a, lradComplex *b)
{
	if (a == NULL)
		return NULL;

	a->real = b->real;
	a->imag = b->imag;

	return a;
}
LRAD_API lradComplex* lradCAssignD(lradComplex *a, double b)
{
	if (a == NULL)
		return NULL;

	a->real = b;
	a->imag = .0;

	return a;
}

LRAD_API lradComplex  lradCAdd(lradComplex a, lradComplex b)
{
	return lradCAdd_Inline(a, b);
}
LRAD_API lradComplex  lradCAddR(lradComplex *a, lradComplex *b)
{
	return lradCAdd_Inline(*a, *b);
}
LRAD_API lradComplex  lradCAddD(lradComplex a, double b)
{
	return lradCAddD_Inline(a, b);
}
LRAD_API lradComplex  lradCAddRd(lradComplex *a, double b)
{
	return lradCAddD_Inline(*a, b);
}
LRAD_API lradComplex* lradCAddI(lradComplex *a, lradComplex b)
{
	if (a == NULL)
		return NULL;

	*a = lradCAdd_Inline(*a, b);

	return a;
}
LRAD_API lradComplex* lradCAddIr(lradComplex *a, lradComplex *b)
{
	if (a == NULL)
		return NULL;

	*a = lradCAdd_Inline(*a, *b);

	return a;
}
LRAD_API lradComplex* lradCAddId(lradComplex *a, double b)
{
	if (a == NULL)
		return NULL;

	*a = lradCAddD_Inline(*a, b);

	return a;
}

LRAD_API lradComplex  lradCSub(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCSubR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCSubD(lradComplex a, double b);
LRAD_API lradComplex  lradCSubRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCSubI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCSubIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCSubId(lradComplex *a, double b);

LRAD_API lradComplex  lradCMult(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCMultR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCMultD(lradComplex a, double b);
LRAD_API lradComplex  lradCMultRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCMultI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCMultIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCMultId(lradComplex *a, double b);

LRAD_API lradComplex  lradCDiv(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCDivR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCDivD(lradComplex a, double b);
LRAD_API lradComplex  lradCDivRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCDivI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCDivIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCDivId(lradComplex *a, double b);

LRAD_API lradComplex  lradCNegate(lradComplex z)
{
	return lradCNegate_Inline(z);
}
LRAD_API lradComplex  lradCNegateS(lradComplex *z)
{
	if (z == NULL)
		return LRAD_NAN;

	return lradCNegate_Inline(*z);
}
LRAD_API lradComplex* lradCNegateI(lradComplex *z)
{
	if (z == NULL)
		return NULL;

	*z = lradCNegate_Inline(*z);

	return z;
}

LRAD_API lradComplex  lradCRotate(lradComplex z, double theta)
{
	const double
		magnitude = sqrt((z.real * z.real) + (z.imag * z.imag)),
		phase     = atan2(z.imag, z.real) + theta,
		x         = magnitude * cos(phase),
		y         = magnitude * sin(phase);

	return (lradComplex) {
		.real = x,
		.imag = y
	};
}
LRAD_API lradComplex  lradCRotateS(lradComplex *z, double theta)
{
	if (z == NULL)
		return LRAD_NAN;

	const double
		magnitude = sqrt((z->real * z->real) + (z->imag * z->imag)),
		phase     = atan2(z->imag, z->real) + theta,
		x         = magnitude * cos(phase),
		y         = magnitude * sin(phase);

	return (lradComplex) {
		.real = x,
		.imag = y
	};
}
LRAD_API lradComplex* lradCRotateI(lradComplex *z, double theta)
{
	if (z == NULL)
		return NULL;

	const double
		magnitude = sqrt((z->real * z->real) + (z->imag * z->imag)),
		phase     = atan2(z->imag, z->real) + theta,
		x         = magnitude * cos(phase),
		y         = magnitude * sin(phase);

	*z = (lradComplex) {
		.real = x,
		.imag = y
	};

	return z;
}

LRAD_API lradComplex  lradCReflectX(lradComplex z)
{
	return 
}
LRAD_API lradComplex  lradCReflectXs(lradComplex *z);
LRAD_API lradComplex* lradCReflectXi(lradComplex *z);

LRAD_API lradComplex  lradCReflectY(lradComplex z);
LRAD_API lradComplex  lradCReflectYs(lradComplex *z);
LRAD_API lradComplex* lradCReflectYi(lradComplex *z);

LRAD_API lradComplex  lradCLn(lradComplex z)
{
	return lradCLn_Inline(z);
}
LRAD_API lradComplex  lradCLnS(lradComplex *z)
{
	if (z == NULL)
		return LRAD_NAN;

	return lradCLn_Inline(*z);
}
LRAD_API lradComplex* lradCLnI(lradComplex *z)
{
	if (z == NULL)
		return NULL;

	*z = lradCLn_Inline(*z);

	return z;
}

LRAD_API lradComplex  lradCLog(lradComplex z, lradComplex b)
{
	lradComplex ln_z = lradCLn_Inline(z), ln_b = lradCLn_Inline(b);

	lradCDivIr(&ln_z, &ln_b);

	return ln_z;
}
LRAD_API lradComplex  lradCLogR(lradComplex *z, lradComplex *b)
{
	if (z == NULL || b == NULL)
		return LRAD_NAN;

	lradComplex ln_z = lradCLn_Inline(*z), ln_b = lradCLn_Inline(*b);

	lradCDivIr(&ln_z, &ln_b);

	return ln_z;
}
LRAD_API lradComplex  lradCLogD(lradComplex z, double b)
{
	lradComplex ln_z = lradCLn_Inline(z);

	lradCDivId(&ln_z, log(b));

	return ln_z;
}
LRAD_API lradComplex  lradCLogRd(lradComplex *z, double b)
{
	if (z == NULL)
		return LRAD_NAN;

	lradComplex ln_z = lradCLn_Inline(*z);

	lradCDivId(&ln_z, log(b));

	return ln_z;
}
LRAD_API lradComplex* lradCLogI(lradComplex *z, lradComplex b)
{
	if (z == NULL)
		return NULL;

	lradComplex ln_b = lradCLn_Inline(b);

	*z = lradCLn_Inline(*z);

	lradCDivIr(z, &ln_b);

	return z;
}
LRAD_API lradComplex* lradCLogIr(lradComplex *z, lradComplex *b)
{
	if (z == NULL || b == NULL)
		return NULL;

	lradComplex ln_b = lradCLn_Inline(*b);

	*z = lradCLn_Inline(*z);

	lradCDivIr(z, &ln_b);

	return z;
}
LRAD_API lradComplex* lradCLogId(lradComplex *z, double b)
{
	if (z == NULL)
		return NULL;

	*z = lradCLn_Inline(*z);

	lradCDivId(z, log(b));

	return z;
}

LRAD_API lradComplex  lradCLog10(lradComplex z)
{
	lradComplex ln_z = lradCLn_Inline(z);

	lradCDivId(&ln_z, log(10.0));

	return ln_z;
}
LRAD_API lradComplex  lradCLog10s(lradComplex *z)
{
	if (z == NULL)
		return LRAD_NAN;

	lradComplex ln_z = lradCLn_Inline(*z);

	lradCDivId(&ln_z, log(10.0));

	return ln_z;
}
LRAD_API lradComplex* lradCLog10i(lradComplex *z)
{
	if (z == NULL)
		return NULL;

	*z = lradCLn_Inline(*z);

	lradCDivId(z, log(10.0));

	return z;
}

LRAD_API double lradCMagnitude(lradComplex z)
{
	return sqrt((z.real * z.real) + (z.imag * z.imag));
}
LRAD_API double lradCMagnitudeS(lradComplex *z)
{
	if (z == NULL)
		return NAN;

	return sqrt((z->real * z->real) + (z->imag * z->imag));
}

LRAD_API double lradCArg(lradComplex z)
{
	return atan2(z.imag, z.real);
}
LRAD_API double lradCArgS(lradComplex *z)
{
	if (z == NULL)
		return NAN;

	return atan2(z->imag, z->real);
}

LRAD_API size_t lradComplexToStr(size_t max_chars, char *buffer, lradComplex z)
{
	return lradComplexToStrEx(max_chars, buffer, 0, &z);
}
LRAD_API size_t lradComplexToStrS(size_t max_chars, char *buffer, lradComplex *z)
{
	return lradComplexToStrEx(max_chars, buffer, 0, z);
}
LRAD_API size_t lradComplexToStrEx(size_t max_chars, char *buffer, size_t spacing, lradComplex *z)
{
	if (z == NULL || buffer == NULL || max_chars == 0)
		return 0;

	int result = snprintf(buffer, max_chars, "%d", z->real);

	if (result != 0) {
	return_fail:
		*buffer = 0;
		return 0;
	}

	const size_t bufsize = max_chars;

	size_t i = strlen(buffer), l = 0;

	char *cursor = NULL;

	max_chars -= i;

	if (max_chars <= ((spacing * 2) + 5))
		goto return_fail;

	for (size_t j = 0; j < spacing; j++, i++)
		buffer[i] = ' ';

	buffer[i++] = '+';

	for (size_t j = 0; j < spacing; j++, i++)
		buffer[i] = ' ';

	cursor = &buffer[i];

	result = snprintf(cursor, max_chars = (bufsize - i), "%d", z->imag);

	if (result != 0)
		goto return_fail;

	l  = strlen(cursor);
	i += l;

	if ((max_chars = (bufsize - i)) < 1) {
		if (l <= 1) {
			buffer[i-1] = 'i';
			return i;
		} else
			goto return_fail;
	} else {
		buffer[i++] = 'i';
		buffer[i+1] = 0;
		return i;
	}
}
