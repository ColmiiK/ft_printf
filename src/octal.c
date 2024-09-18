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

// Field minimum width, left justify, precision, space, sign
void ft_resolve_octal(t_format *tab)
{
	int		len;
	long	n;
	
	n = va_arg(tab->arg, int);
	len = digit_count(n, 8);
	if (!n)
		tab->total += write(STDOUT_FILENO, "0", 1);
	else if (tab->dash)
	{
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		tab->precision -= len;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, "01234567");
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->precision -= len;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, "01234567");
	}
	else
	{
		tab->precision -= len;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, "01234567");
	} 
}

