#include "../include/ft_printf.h"
#include <unistd.h>

static int	ft_print_number(int n, char *base)
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

static int	ft_print_float(t_format *tab, double n, int exponent, char c)
{

}

// Field minimum width, left justify, precision, space, sign
void ft_resolve_alternate_float(t_format *tab, char c)
{
	double	n;
	int exponent;

	exponent = 0;
	n = va_arg(tab->arg, double);
	while (n >= 10.0)
	{
		n /= 10.0;
		exponent++;
	}
	tab->total += ft_print_float(tab, n , exponent, c);
}

