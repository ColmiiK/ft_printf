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
*		#o
*	TODO
*		#x (add 0x)
*		#X (add 0x)
*		#e
*		#F
*		#g
*		#G
* */

# define CONVERSION "->%#.5o<-"
# define TOPRINT 42

int main(){
	char *str = "Hello";
	int total1 = printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total1);
	int total2 = ft_printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total2);
}
