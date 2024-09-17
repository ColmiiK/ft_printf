#include "../include/ft_printf.h"

int	ft_print_unsigned_number(unsigned long n, char *base)
{

	size_t len;

	len = ft_strlen(base);
	if (len == 16)
		return (ft_print_unsigned_number((unsigned int)n, base));
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base) + ft_print_unsigned_number(n % len, base));
}

void ft_resolve_unsigned_number(t_format *tab, char *base)
{
	// fix format for unsigned number

	tab->total += ft_print_unsigned_number(va_arg(tab->arg, long), base);
}

