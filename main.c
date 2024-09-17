#include "include/ft_printf.h"

// make && gcc main.c -L. -lftprintf -Llib/libft -lft && ./a.out

int main(){	
	//printf("Output should be: ->%10c<-\n", 'a');
	int total = ft_printf("aaaaaa->%10c<-\n", 'a');
}
