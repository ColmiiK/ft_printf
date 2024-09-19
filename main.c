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
*		#x (add 0x)
*		#X (add 0x)
*		#E
*		#e
*		#f
*		#F
*		if there is no precision specified (ie. "%#.e") doesn't work properly, change check
*		#g
*		#G
*	TODO
*		#f long numbers overflow (fix?)
* */

# define CONVERSION "->%#20.10g<-"
# define TOPRINT 112312.1234

int main(){
	char *str = "Hello";
	int total1 = printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total1);
	int total2 = ft_printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total2);
}
