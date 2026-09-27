
#ifndef _LIBRADIAL__symbolmanip_FUNCTIONS_H_
#define _LIBRADIAL__symbolmanip_FUNCTIONS_H_ 1

#ifndef _LIBRADIAL_
#	include <libradial.h>
#endif

LRAD_EXTERN_C



enum _lrad_function_argtype
{
	_LRAD_NULL_ARGTYPE = 0,

	LRAD_DOUBLE_ARG  = 1,
	LRAD_FLOAT_ARG,
	LRAD_COMPLEX_ARG,
	LRAD_VEC2_ARG,
	LRAD_VEC3_ARG,
	LRAD_VEC4_ARG,
	LRAD_FVEC2_ARG,
	LRAD_FVEC3_ARG,
	LRAD_FVEC4_ARG,
	LRAD_SET_ARG,
	LRAD_FUNCEXPR_ARG,
	LRAD_ANY_ARG,

	_LRAD_MAX_ARGTYPE = LRAD_ANY_ARG,
	_LRAD_SYMBOL_OFFSET = 32,
};

typedef enum _lrad_function_type
{
	LRAD_DIRECT,
	LRAD_MAPPER,
	LRAD_EXPR_ONLY,

	LRAD_FUNCTYPE_VARIADIC = (1 << 7),
} lrad_function_type;

typedef uint64_t lrad_function_argtype;
typedef unsigned char lrad_function_type;

lrad_function_argtype lrad_make_argtype(int argtype_id, lrad_symbol name);

typedef struct _lrad_func_table_entry
{
	lrad_function_type    functype;
	lrad_function_argtype args[4];
	void                 *addr;
	lrad_expression       expression;
} lrad_func_table_entry_t;

/* typedef */ struct _lrad_lambda
{
	lrad_func_table_entry_t func;

	void **params;
	size_t paramc;
} /* lrad_lambda_t */;

lrad_func_table_entry_t lrad_make_func_table_entry(void *const function_addr, lrad_expression expr, size_t n, lrad_function_argtype *args);
lrad_func_table_entry_t lrad_make_func_table_entry(lrad_expression expr, size_t n, lrad_function_argtype *args);
lrad_func_table_entry_t lrad_make_func_table_entry_m(lrad_sym_mapper_t function_addr, size_t n, lrad_function_argtype *args);
lrad_func_table_entry_t lrad_make_func_table_entry_v(lrad_sym_mapper_t variadic_mapper);

bool         lrad_sym_ne(double a, double b);
bool         lrad_sym_ne(float a, float b);
bool         lrad_sym_ne(lrad_complex a, lrad_complex b);

bool         lrad_sym_eq(double a, double b);
bool         lrad_sym_eq(float a, float b);
bool         lrad_sym_eq(lrad_complex a, lrad_complex b);

bool         lrad_sym_lt(double a, double b);
bool         lrad_sym_lt(float a, float b);

bool         lrad_sym_le(double a, double b);
bool         lrad_sym_le(float a, float b);

bool         lrad_sym_gt(double a, double b);
bool         lrad_sym_gt(float a, float b);

bool         lrad_sym_ge(double a, double b);
bool         lrad_sym_ge(float a, float b);

double       lrad_sym_abs(double a);
float        lrad_symf_abs(float a);
lrad_complex lrad_symc_abs(lrad_complex z);

double       lrad_sym_add(double a, double b);
float        lrad_symf_add(float a, float b);
lrad_complex lrad_symc_add(lrad_complex z, lrad_complex w);

double       lrad_sym_sub(double a, double b);
float        lrad_symf_sub(float a, float b);
lrad_complex lrad_symc_sub(lrad_complex z, lrad_complex w);

double       lrad_sym_mul(double a, double b);
float        lrad_symf_mul(float a, float b);
lrad_complex lrad_symc_mul(lrad_complex z, lrad_complex w);

double       lrad_sym_div(double a, double b);
float        lrad_symf_div(float a, float b);
lrad_complex lrad_symc_div(lrad_complex z, lrad_complex w);

double       lrad_sym_ln(double x);
float        lrad_symf_ln(float x);
lrad_complex lrad_symc_ln(lrad_complex z);

double       lrad_sym_exp(double x);
float        lrad_symf_exp(float x);
lrad_complex lrad_symc_exp(lrad_complex x);

double       lrad_sym_pow(double base, double exponent);
float        lrad_symf_pow(float base, float exponent);
lrad_complex lrad_symc_pow(lrad_complex base, lrad_complex exponent);

double       lrad_sym_sin(double theta);
float        lrad_symf_sin(float theta);
lrad_complex lrad_symc_sin(lrad_complex theta);

lrad_expression lrad_differentiate(lrad_expression expr, lrad_symbol differential);
lrad_expression lrad_integrate(lrad_expression expr, lrad_symbol differential);



LRAD_END_EXTERN_C

#endif // _LIBRADIAL__symbolmanip_FUNCTIONS_H_
