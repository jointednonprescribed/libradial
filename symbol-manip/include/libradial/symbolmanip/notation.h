
#ifndef _LIBRADIAL__symbolmanip_NOTATION_H_
#define _LIBRADIAL__symbolmanip_NOTATION_H_ 1

#include <libradial.h>

LIBRADIAL_EXTERN_C



typedef struct _lrad_expr
{
	uint32_t    flags;
	float       shortval;
	const void *ref;
} lrad_expr, lrad_expression;


typedef uint32_t lrad_symbol, lrad_sym;

enum LRAD_SYMBOL_MARKS
{
	LRAD_MARK_SYM_ASCII     = (1  << 21),
	LRAD_MARK_SYM_ASCII2    = (2  << 21),
	LRAD_MARK_SYM_ASCII3    = (3  << 21),
	LRAD_MARK_SYM_UNICODE   = (4  << 21),
	LRAD_MARK_SYM_WRAPPING  = (5  << 21),
	LRAD_MARK_CONST_ASCII   = (6  << 21),
	LRAD_MARK_CONST_ASCII2  = (7  << 21),
	LRAD_MARK_CONST_ASCII3  = (8  << 21),
	LRAD_MARK_CONST_UNICODE = (9  << 21),
	LRAD_MARK_CONST_REF     = (10 << 21),
	LRAD_MARK_REF           = (11 << 21),
	LRAD_MARK_FUNC          = (12 << 21),
	LRAD_MARK_PREV_EXPR     = (13 << 21),
	LRAD_MARK_NEXT_EXPR     = (14 << 21),
	LRAD_MARK_EXPR          = (15 << 21),

	_LRAD_MARK_LARGEST      = LRAD_MARK_EXPR,

	LRAD_MARK_DIFFERENTIAL  = (1  << 29),

	LRAD_MARK_SYMW_OPEN     = (1  << 31),
	LRAD_MARK_SYMW_CLOSE    = (1  << 30),
	LRAD_SYMW_MASK          = (3  << 30),
	LRAD_SYMW_NMASK         = (~LRAD_SYMW_MASK),
};

#define LRAD_PREV_EXPR ((lrad_symbol)LRAD_MARK_PREV_EXPR)
#define LRAD_NEXT_EXPR ((lrad_symbol)LRAD_MARK_NEXT_EXPR)

#define LRAD_SYM(symbolchar)         ((lrad_symbol)(LRAD_MARK_SYM_ASCII    | (symbolchar)))
#define LRAD_SYMW(opensym, closesym) ((lrad_symbol)(LRAD_MARK_SYM_WRAPPING | (opensym) | (closesym << 7)))
#define LRAD_SYMW_OPEN(sym)          ((sym) | LRAD_MARK_SYMW_OPEN)
#define LRAD_SYMW_CLOSE(sym)         ((sym) | LRAD_MARK_SYMW_CLOSE)
#define LRAD_SYM2(sym1, sym2)        ((lrad_symbol)(LRAD_MARK_SYM_ASCII2   | (sym1) | (sym2 << 7)))
#define LRAD_SYM2(sym1, sym2, sym3)  ((lrad_symbol)(LRAD_MARK_SYM_ASCII3   | (sym1) | (sym2 << 7) | (sym3 << 14)))
#define LRAD_REF(index)              ((lrad_symbol)(LRAD_MARK_REF          | (index)))
#define LRAD_USYM(symbolchar)        ((lrad_symbol)(LRAD_MARK_SYM_UNICODE  | (symbolchar)))

LRAD_API lrad_symbol lrad_make_sym(char symbol);
LRAD_API lrad_symbol lrad_make_symw(char open, char close);
LRAD_API lrad_symbol lrad_make_sym2(char sym1, char sym2);
LRAD_API lrad_symbol lrad_make_ref(int reference_index);
LRAD_API lrad_symbol lrad_make_refs(const char *str);
LRAD_API lrad_symbol lrad_make_usym(int usym);

LRAD_API lrad_symbol lrad_make_const(char symbol, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_const2(char sym1, char sym2, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_uconst(int usym, lrad_expr expression);

LRAD_API lrad_symbol lrad_make_const(char symbol, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_const2(char sym1, char sym2, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_uconst(int usym, lrad_expr expression);

LRAD_API lrad_symbol lrad_make_const(char symbol, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_const2(char sym1, char sym2, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_uconst(int usym, lrad_expr expression);

LRAD_API lrad_symbol lrad_make_ref(const char *name);
LRAD_API lrad_symbol lrad_make_refi(int reference_index);

LRAD_API int         lrad_ref_resolve(const char *name);
LRAD_API lrad_symbol lrad_ref_resolves(const char *name);
LRAD_API bool        lrad_ref_exists(const char *name);
LRAD_API bool        lrad_ref_existsi(int reference_index);

LRAD_API int         lrad_func_resolve(const char *name);
LRAD_API lrad_symbol lrad_func_resolves(const char *name);
LRAD_API bool        lrad_func_exists(const char *name);
LRAD_API bool        lrad_func_existsi(int reference_index);

LRAD_API lrad_symbol lrad_symw_open(lrad_symbol sym);
LRAD_API lrad_symbol lrad_symw_close(lrad_symbol sym);

enum LRAD_SYM_CONSTANTS
{
	// Statement Separator
	LRAD_SYM_SEP       = LRAD_SYM(';'),
	// Tuple Separator
	LRAD_SYM_TSEP      = LRAD_SYM(','),
	// Subscript / Matrix Creation Operator
	LRAD_SYM_SUBSCRIPT = LRAD_SYMW('[', ']'),
	// Generic Parenthesis / Tuple Generation Operator
	LRAD_SYM_PAREN     = LRAD_SYMW('(', ')'),
	// Generic Curly Brackets / Picewise Operator / Set Generation Operator / Domain Specification Operator
	LRAD_SYM_CBRACKETS = LRAD_SYMW('{', '}'),
	// Assignment / Equality Operator
	LRAD_SYM_EQ        = LRAD_SYM('='),
	// Inequality Operator
	LRAD_SYM_NE        = LRAD_SYM('!', '='),
	// Alternative Inequality Operator
	LRAD_SYM_NE_ALT    = LRAD_SYM2('~', '='),
	// Less-Than Operator
	LRAD_SYM_LT        = LRAD_SYM('<'),
	//Less-Than-or-Equal Operator
	LRAD_SYM_LE        = LRAD_SYM2('<', '='),
	// Greater-Than Operator
	LRAD_SYM_GT        = LRAD_SYM('>'),
	// Greater-Than-or-Equal Operator
	LRAD_SYM_GE        = LRAD_SYM2('>', '='),
	// Logical Not Operator
	LRAD_SYM_NOT       = LRAD_SYM('~'),
	// Logical Or Operator
	LRAD_SYM_OR        = LRAD_SYM('|'),
	// Logical And Operator
	LRAD_SYM_AND       = LRAD_SYM('&'),
	// Logical Exclusive Or Operator
	LRAD_SYM_ASC_XOR   = LRAD_SYM3('<', '/', '>'),
	// Logical Exclusive Or Operator (Unicode)
	LRAD_SYM_XOR       = LRAD_USYM('\u22bb'),

	// Vector Creation Operator
	LRAD_SYM_VEC       = LRAD_SYMW('<', '>'),

	// Absolute Value Operator
	LRAD_SYM_ABS       = LRAD_SYMW('|', '|'),

	// Exponentiation Operator
	LRAD_SYM_EXP       = LRAD_SYM('^'),

	// Addition Operator
	LRAD_SYM_ADD       = LRAD_SYM('+'),
	// Subtraction Operator
	LRAD_SYM_SUB       = LRAD_SYM('-'),
	// Multiplication Operator
	LRAD_SYM_MUL       = LRAD_SYM('*'),
	// Division Operator
	LRAD_SYM_DIV       = LRAD_SYM('/'),

	// Square Root Operator
	LRAD_SYM_ASC_SQRT  = LRAD_SYM2('_', '/'),
	// Square Root Operator (Unicode)
	LRAD_SYM_SQRT      = LRAD_USYM('\u221a'),
	/* Differentiation (Leibniz Notation is used by libradial as a syntactical
	 * standard for denoting derivatives, differentiation, and differentials
	 * themselves, although Lagrange Notation is used as well for differentials
	 * themselves in the context of differential equations):
	 *  " d/dx(f(x)) "
	 *  " y + y' - z'' = 2x " */
	LRAD_SYM_DIF_LEIB  = LRAD_SYM('d'),
	LRAD_SYM_DIF_LAGR  = LRAD_SYM('\''),
	// Integration: " ||f(x)dx " or " ∫f(x)dx "
	LRAD_SYM_ASC_INT   = LRAD_SYM2('|', '|'),
	LRAD_SYM_INT       = LRAD_USYM('\u222b'),
};

typedef struct _lrad_symbol_registry *lrad_symbol_registry_t;
typedef struct _lrad_function_table  *lrad_function_table_t;
typedef struct _lrad_parsing_context *lrad_parsing_context_t;



LRAD_END_EXTERN_C

#endif // _LIBRADIAL__symbolmanip_NOTATION_H_
