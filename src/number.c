#include "../include/ft_printf.h"

int	ft_print_number(long n, char *base)
{
	size_t len;

	len = ft_strlen(base);
	if (n < 0 && len == 10)
		return (write(1, "-", 1) + ft_print_number(n * -1, base));
	if (n < 0 && len == 16)
		return (ft_print_number((unsigned int)n, base));
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_number(n / len, base) + ft_print_number(n % len, base));
}

void ft_resolve_number(t_format *tab, char *base)
{
	// fix format for number

	tab->total += ft_print_number(va_arg(tab->arg, long), base);
}

