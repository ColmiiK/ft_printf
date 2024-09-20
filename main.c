#include "include/ft_printf.h"

// make && gcc main.c -L. -lftprintf -Llib/libft -lft && ./a.out

# define CONVERSION "%#x"
# define TOPRINT 0

int main(){
	char *str = NULL;
	printf("\"%s\"\n", CONVERSION);
	int total1 = printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total1);
	int total2 = ft_printf(CONVERSION, TOPRINT);
	printf(" (%d)\n", total2);
}
