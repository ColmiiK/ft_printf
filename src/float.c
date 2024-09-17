#include "../include/ft_printf.h"

int	ft_print_float(int n)
{
	(void)n;
	return 0;
}

void ft_resolve_float(t_format *tab)
{
	// fix format for float

	tab->total += ft_print_float(va_arg(tab->arg, int));
}
