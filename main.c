#include "include/ft_printf.h"

// make && gcc main.c -L. -lftprintf -Llib/libft -lft && ./a.out

int main(){

	int total = ft_printf("%#o\n", 42);
	ft_printf("Total is %d\n", total);
}
