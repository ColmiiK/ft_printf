#include "../include/ft_printf.h"

static int	ft_print_unsigned_number(unsigned long n, char *base)
{
	size_t len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base) + ft_print_unsigned_number(n % len, base));
}

// Field minimum width, left justify, precision
void ft_resolve_unsigned_number(t_format *tab, long n, char *base)
{
	int len;

	len = digit_count(n, 10);
	if (tab->dash)
	{
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
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
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
	} 
}
