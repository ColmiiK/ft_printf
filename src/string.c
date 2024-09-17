#include "../include/ft_printf.h"

int	ft_print_string(char *str)
{
	size_t total;

	total = 0;
	if (!str)
		str = "(null)";
	while (*str)
		total += write(STDOUT_FILENO, str++, 1);
	return (total);
}

void ft_resolve_string(t_format *tab)
{
	// fix format for string

	tab->total += ft_print_string(va_arg(tab->arg, char *));
}

