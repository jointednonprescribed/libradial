
#ifndef _LIBRADIAL__types_COMPLEX_H_
#define _LIBRADIAL__types_COMPLEX_H_ 1

#ifndef _LIBRADIAL__INCLUDES_H_
#	include "../includes.h"
#endif
#ifndef _LIBRADIAL__types_spec_VEC_TYPES_H_
#	include "spec/vec-types.h"
#endif



LRAD_EXTERN_C


/* Implementation for struct _lradComplex */
struct LRAD_API _lradComplex
{
	double real, imag;
};

#define LRAD_I         (lradComplex) { .real = .0,         .imag = 1.0 }
#define LRAD_PI        (lradComplex) { .real = M_PI,       .imag = .0  }
#define LRAD_E         (lradComplex) { .real = M_E,        .imag = .0  }
#define LRAD_LOG2E     (lradComplex) { .real = M_LOG2E,    .imag = .0  }
#define LRAD_LOG10E    (lradComplex) { .real = M_LOG10E,   .imag = .0  }
#define LRAD_LN2       (lradComplex) { .real = M_LN2,      .imag = .0  }
#define LRAD_PI_2      (lradComplex) { .real = M_PI_2,     .imag = .0  }
#define LRAD_PI_4      (lradComplex) { .real = M_PI_4,     .imag = .0  }
#define LRAD_1_PI      (lradComplex) { .real = M_1_PI,     .imag = .0  }
#define LRAD_2_PI      (lradComplex) { .real = M_2_PI,     .imag = .0  }
#define LRAD_2_SQRTPI  (lradComplex) { .real = M_2_SQRTPI, .imag = .0  }
#define LRAD_SQRT2     (lradComplex) { .real = M_SQRT2,    .imag = .0  }
#define LRAD_SQRT1_2   (lradComplex) { .real = M_SQRT1_2,  .imag = .0  }
#define LRAD_NAN       (lradComplex) { .real = NAN,        .imag = NAN }

#define lradComplexIsNan_Inline(z)  (((z).real == NAN) && ((z).imag == NAN))
#define lradComplexHasNan_Inline(z) (((z).real == NAN) || ((z).imag == NAN))

LRAD_API lradComplex lradComplex_Make();
LRAD_API lradComplex lradComplex_MakeR(double real);
LRAD_API lradComplex lradComplex_MakeC(double real, double imag);
LRAD_API lradComplex lradComplex_MakeI(double imag);

#define      lradComplex_Make_Inline(...)   (lradComplex){.real=.0, .imag=.0}
#define      lradComplex_MakeR_Inline(r)    (lradComplex){.real=r,  .imag=.0}
#define      lradComplex_MakeC_Inline(r, i) (lradComplex){.real=r,  .imag=i}
#define      lradComplex_MakeI_Inline(i)    (lradComplex){.real=.0, .imag=i}

LRAD_API lradComplex* lradComplex_Init(lradComplex *self);
LRAD_API lradComplex* lradComplex_InitR(lradComplex *self, double real);
LRAD_API lradComplex* lradComplex_InitC(lradComplex *self, double real, double imag);
LRAD_API lradComplex* lradComplex_InitI(lradComplex *self, double imag);

LRAD_API lradvec2     lradComplexToVec2s(lradComplex *self);
LRAD_API int          lradComplexToVec2r(lradComplex *self, lradvec2 *vec);
LRAD_API lradvec2     lradComplexToVec2(lradComplex v);
LRAD_API lradpvec2    lradComplexToPVec2s(lradComplex *self);
LRAD_API int          lradComplexToPVec2r(lradComplex *self, lradpvec2 *vec);
LRAD_API lradpvec2    lradComplexToPVec2(lradComplex v);

#define      lradComplexToVec2_Inline(z)  (lradvec2) { .v = { (z).real, (z).imag } }
#define      lradComplexToPVec2_Inline(z) (lradvec2) { .v = { \
	sqrt(((z).real * (z).real) + ((z).imag * (z).imag)),      \
	atan2((z).imag, (z).real)                                 \
} }

LRAD_API lradComplex* lradCAssign(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCAssignR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCAssignD(lradComplex *a, double b);

LRAD_API lradComplex  lradCAdd(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCAddR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCAddD(lradComplex a, double b);
LRAD_API lradComplex  lradCAddRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCAddI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCAddIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCAddId(lradComplex *a, double b);

#define lradCAdd_Inline(w, z)  (lradComplex) { .real = (w).real + (z).real, .imag = (w).imag + (z).imag }
#define lradCAddD_Inline(z, d) (lradComplex) { .real = (z).real + (d), .imag = (z).imag }

LRAD_API lradComplex  lradCSub(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCSubR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCSubD(lradComplex a, double b);
LRAD_API lradComplex  lradCSubRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCSubI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCSubIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCSubId(lradComplex *a, double b);

#define lradCSub_Inline(w, z)  (lradComplex) { .real = (w).real - (z).real, .imag = (w).imag - (z).imag }
#define lradCSubD_Inline(z, d) (lradComplex) { .real = (z).real - (d), .imag = (z).imag }

LRAD_API lradComplex  lradCMult(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCMultR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCMultD(lradComplex a, double b);
LRAD_API lradComplex  lradCMultRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCMultI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCMultIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCMultId(lradComplex *a, double b);

#define lradCMult_Inline(w, z)  (lradComplex) { .real = ((w).real * (z).real) - ((w).imag * (z).imag), .imag = ((w).real * (z).imag) + ((w).imag * (z).real) }
#define lradCMultD_Inline(z, d) (lradComplex) { .real = (z).real * (d), .imag = (z).imag * (d) }

LRAD_API lradComplex  lradCDiv(lradComplex a, lradComplex b);
LRAD_API lradComplex  lradCDivR(lradComplex *a, lradComplex *b);
LRAD_API lradComplex  lradCDivD(lradComplex a, double b);
LRAD_API lradComplex  lradCDivRd(lradComplex *a, double b);
LRAD_API lradComplex* lradCDivI(lradComplex *a, lradComplex b);
LRAD_API lradComplex* lradCDivIr(lradComplex *a, lradComplex *b);
LRAD_API lradComplex* lradCDivId(lradComplex *a, double b);

LRAD_API lradComplex  lradCNegate(lradComplex z);
LRAD_API lradComplex  lradCNegateS(lradComplex *z);
LRAD_API lradComplex* lradCNegateI(lradComplex *z);

#define lradCNegate_Inline(z) (lradComplex) { .real = -((z).real), .imag = -((z).imag) }

LRAD_API lradComplex  lradCRotate(lradComplex z, double theta);
LRAD_API lradComplex  lradCRotateS(lradComplex *z, double theta);
LRAD_API lradComplex* lradCRotateI(lradComplex *z, double theta);

LRAD_API lradComplex  lradCRotate(lradComplex z, double theta);
LRAD_API lradComplex  lradCRotateS(lradComplex *z, double theta);
LRAD_API lradComplex* lradCRotateI(lradComplex *z, double theta);

LRAD_API lradComplex  lradCReflectX(lradComplex z);
LRAD_API lradComplex  lradCReflectXs(lradComplex *z);
LRAD_API lradComplex* lradCReflectXi(lradComplex *z);

#define lradCReflectX_Inline(z) (lradComplex) { .real = -((z).real), .imag = (z).imag }

LRAD_API lradComplex  lradCReflectY(lradComplex z);
LRAD_API lradComplex  lradCReflectYs(lradComplex *z);
LRAD_API lradComplex* lradCReflectYi(lradComplex *z);

#define lradCReflectY_Inline(z) (lradComplex) { .real = (z).real, .imag = -((z).imag) }

LRAD_API lradComplex  lradCInverse(lradComplex z);
LRAD_API lradComplex  lradCInverseS(lradComplex *z);
LRAD_API lradComplex* lradCInverseI(lradComplex *z);

#define lradCInverse_Inline(z) (lradComplex) { .real = -((z).imag), .imag = (z).real }

LRAD_API lradComplex  lradCReciprocal(lradComplex z);
LRAD_API lradComplex  lradCReciprocalS(lradComplex *z);
LRAD_API lradComplex* lradCReciprocalI(lradComplex *z);

#define lradCReciprocal_Inline(z) (lradComplex) { .real = (z).imag, .imag = (z).real }

LRAD_API lradComplex  lradCLn(lradComplex z);
LRAD_API lradComplex  lradCLnS(lradComplex *z);
LRAD_API lradComplex* lradCLnI(lradComplex *z);
// Natural Logarithm method:
// ln(z) = ln(|z|) + iarg(z),
// |z| = sqrt(a^2 + b^2), arg(z) = arctan(b / a), where z = a + bi
#define lradCLn_Inline(z) (lradComplex) {                           \
	.real = log(sqrt( ((z).real*(z).real) + ((z).imag*(z).imag) )), \
	.imag = atan2((z).imag, (z).real)                               \
}

// Logarithm with Base 'b' Method:
//  Log base 10 implements b as a double literal `10.0`
// logb(z) = ln(z) / ln(b)
LRAD_API lradComplex  lradCLog(lradComplex z, lradComplex base);
LRAD_API lradComplex  lradCLogR(lradComplex *z, lradComplex *base);
LRAD_API lradComplex  lradCLogD(lradComplex z, double base);
LRAD_API lradComplex  lradCLogRd(lradComplex *z, double base);
LRAD_API lradComplex* lradCLogI(lradComplex *z, lradComplex base);
LRAD_API lradComplex* lradCLogIr(lradComplex *z, lradComplex *base);
LRAD_API lradComplex* lradCLogId(lradComplex *z, double base);

LRAD_API lradComplex  lradCLog10(lradComplex z);
LRAD_API lradComplex  lradCLog10s(lradComplex *z);
LRAD_API lradComplex* lradCLog10i(lradComplex *z);

LRAD_API double       lradCMagnitude(lradComplex z);
LRAD_API double       lradCMagnitudeS(lradComplex *z);
LRAD_API lradComplex  lradCMagnify(lradComplex z, double factor);
LRAD_API lradComplex* lradCMagnifyI(lradComplex *z, double factor);
LRAD_API lradComplex  lradCAddMagnitude(lradComplex z, double n);
LRAD_API lradComplex* lradCAddMagnitudeI(lradComplex *z, double n);

LRAD_API double       lradCArg(lradComplex z);
LRAD_API double       lradCArgS(lradComplex *z);

LRAD_API size_t       lradComplexToStr(size_t buffer_size, char *buffer, lradComplex z);
LRAD_API size_t       lradComplexToStrS(size_t buffer_size, char *buffer, lradComplex *z);
LRAD_API size_t       lradComplexToStrEx(size_t buffer_size, char *buffer, size_t spacing, lradComplex *z);


LRAD_END_EXTERN_C



#endif // _LIBRADIAL__types_COMPLEX_H_
