#include "include/ft_printf.h"

// make && gcc main.c -L. -lftprintf -Llib/libft -lft && ./a.out

int main(){	
	printf("%10d\n", 42);
	int total = ft_printf("%10d\n", 42);
}
