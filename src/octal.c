#include "../include/ft_printf.h"
#include <unistd.h>

void ft_resolve_octal(t_format *tab, int n)
{
	int		len;
	
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

