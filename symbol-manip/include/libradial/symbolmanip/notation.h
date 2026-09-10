
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
	LRAD_MARK_SYM_ASCII     = (1  << 20),
	LRAD_MARK_SYM_ASCII2    = (2  << 20),
	LRAD_MARK_SYM_UNICODE   = (3  << 20),
	LRAD_MARK_SYM_WRAPPING  = (4  << 20),
	LRAD_MARK_CONST_ASCII   = (5  << 20),
	LRAD_MARK_CONST_ASCII2  = (6  << 20),
	LRAD_MARK_CONST_UNICODE = (7  << 20),
	LRAD_MARK_REF           = (8  << 20),
	LRAD_MARK_PREV_EXPR     = (9  << 20),
	LRAD_MARK_NEXT_EXPR     = (10 << 20),
	LRAD_MARK_EXPR          = (11 << 20),

	LRAD_MARK_SYMW_OPEN     = (1  << 31),
	LRAD_MARK_SYMW_CLOSE    = (1  << 30),
	LRAD_SYMW_MASK          = (3  << 30),
};

#define LRAD_PREV_EXPR ((lrad_symbol)LRAD_MARK_PREV_EXPR)
#define LRAD_NEXT_EXPR ((lrad_symbol)LRAD_MARK_NEXT_EXPR)

#define LRAD_SYM(symbolchar)         ((lrad_symbol)(LRAD_MARK_SYM_ASCII    | (symbolchar)))
#define LRAD_SYMW(opensym, closesym) ((lrad_symbol)(LRAD_MARK_SYM_WRAPPING | (opensym) | (closesym << 8)))
#define LRAD_SYMW_OPEN(sym)          ((sym) | LRAD_MARK_SYMW_OPEN)
#define LRAD_SYMW_CLOSE(sym)         ((sym) | LRAD_MARK_SYMW_CLOSE)
#define LRAD_SYM2(sym1, sym2)        ((lrad_symbol)(LRAD_MARK_SYM_ASCII2   | (sym1) | (sym2 << 8)))
#define LRAD_REF(index)              ((lrad_symbol)(LRAD_MARK_REF          | (index)))
#define LRAD_USYM(symbolchar)        ((lrad_symbol)(LRAD_MARK_SYM_UNICODE  | (symbolchar)))

LRAD_API lrad_symbol lrad_make_sym(char symbol);
LRAD_API lrad_symbol lrad_make_sym2(char sym1, char sym2);
LRAD_API lrad_symbol lrad_make_usym(int usym);

LRAD_API lrad_symbol lrad_make_const(char symbol, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_const2(char sym1, char sym2, lrad_expr expression);
LRAD_API lrad_symbol lrad_make_uconst(int usym, lrad_expr expression);

LRAD_API lrad_symbol lrad_make_ref(const char *name);
LRAD_API lrad_symbol lrad_make_refi(int reference_index);

LRAD_API int  lrad_ref_resolve(const char *name);
LRAD_API bool lrad_ref_is_func(const char *name);
LRAD_API bool lrad_ref_is_var(const char *name);
LRAD_API bool lrad_ref_is_funci(int reference_index);
LRAD_API bool lrad_ref_is_vari(int reference_index);

enum LRAD_SYM_CONSTANTS
{
	LRAD_SYM_SEP       = LRAD_SYM(';'),
	LRAD_SYM_SUBSCRIPT = LRAD_SYMW('[', ']'),
	LRAD_SYM_PAREN     = LRAD_SYMW('(', ')'),

	LRAD_SYM_ADD       = LRAD_SYM('+'),
	LRAD_SYM_SUB       = LRAD_SYM('-'),
	LRAD_SYM_MUL       = LRAD_SYM('*'),
	LRAD_SYM_DIV       = LRAD_SYM('/'),
	/* Differentiation (Leibniz Notation is used by libradial as a syntactical
	 * standard for denoting derivatives, differentiation, and differentials themselves):
	 *  " d/dx(f(x)) " */
	LRAD_SYM_DIF       = LRAD_SYM('d'),
	/* Integration: " ||f(x)dx " or " ∫f(x)dx " */
	LRAD_SYM_ASC_INT   = LRAD_SYM2('|', '|'),
	LRAD_SYM_INT       = LRAD_USYM('\u222b'),
};



LRAD_END_EXTERN_C

#endif // _LIBRADIAL__symbolmanip_NOTATION_H_
