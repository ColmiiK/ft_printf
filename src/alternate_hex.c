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
void ft_resolve_alternate_hex(t_format *tab, char *base)
{
	int len;
	long n;

	n = va_arg(tab->arg, long);
	len = digit_count(n, 10);
	tab->width -= 2;
	if (tab->dash)
	{
		tab->total += write(STDOUT_FILENO, "0x", 2);
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
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
	} 
}
