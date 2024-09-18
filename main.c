#include "include/ft_printf.h"

// make && gcc main.c -L. -lftprintf -Llib/libft -lft && ./a.out

/*
*	DONE
*		c
*		%
*		s
*		d
*		u
*		i
*		x
*		X
*		p (add 0x)
*		FIX NEGATIVE NUMBERS ON d
*	TODO
*		#o
*		#x (add 0x)
*		#X (add 0x)
*		#e
*		#F
*		#g
*		#G
*
*
* */

# define CONVERSION "->%-20.10d<-"
# define TOPRINT -42

int main(){
	char *str = "Hello";
	int total1 = printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total1);
	int total2 = ft_printf(CONVERSION, TOPRINT);
	ft_printf(" (%d)\n", total2);
}
