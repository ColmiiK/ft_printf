#include "../include/ft_printf.h"

int	ft_print_char(char c)
{
	size_t total;

	total = 0;
	total += write(STDOUT_FILENO, &c, 1);
	return (total);
}

void ft_resolve_char(t_format *tab)
{
	// fix format for char
	
	tab->total += ft_print_char(va_arg(tab->arg, int));
}

