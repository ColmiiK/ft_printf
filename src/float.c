#include "../include/ft_printf.h"

static int	ft_print_float(double n, int precision)
{
	long	integer;
	float	fractional;
	int		total;
	int		digit;

	total = 0;
	integer = (int)n;
	fractional = n - integer;
	total += ft_print_number(integer, "0123456789");
	total += write(STDOUT_FILENO, ".", 1);
	while (precision-- > 0)
	{
		fractional *= 10;
		digit = (int)fractional;
		if (digit < 0)
			digit = -digit;
		total += ft_print_number(digit, "0123456789");
        if ((int)fractional < 0)
			digit *= -1;
		fractional -= digit;
	}
	return (total);
}

void ft_resolve_float(t_format *tab, double n)
{
	int len;

	len = digit_count((int)n, 10);
	if (tab->sign && n >= 0)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (tab->dash)
	{
		if (tab->dot)
			tab->width -= tab->precision + len;
		else
		 	tab->width -= 6 + len;
		if (tab->dot)
			tab->total += ft_print_float(n, tab->precision);
		else
			tab->total += ft_print_float(n, 6);
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if (tab->dot)
			tab->width -= tab->precision + len;
		else
		 	tab->width -= 6 + len;
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		if (tab->dot)
			tab->total += ft_print_float(n, tab->precision);
		else
			tab->total += ft_print_float(n, 6);
	}
	else
	{
		if (tab->dot)
			tab->total += ft_print_float(n, tab->precision);
		else
			tab->total += ft_print_float(n, 6);
	}
}
