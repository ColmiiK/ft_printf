#include "../include/ft_printf.h"
#include <unistd.h>

static int	ft_print_unsigned_number(unsigned int n, char *base)
{
	size_t len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base) + ft_print_unsigned_number(n % len, base));
}

/*void ft_resolve_unsigned_number(t_format *tab, unsigned int n, char *base)
{
	int len;

	len = digit_count(n, 10);
	if (!n && tab->pad == ' ' && !tab->dot && !tab->width)
		tab->total += write(STDOUT_FILENO, "0", 1);
	else if (tab->dash)
	{
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		if (tab->dot && tab->precision < 0 && !n)
			tab->width++;
		else
			tab->total += ft_print_unsigned_number(n, base);
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if (!n && tab->pad == '0')
		{
			tab->pad = ' ';
			if (tab->dot)
			{
				tab->width++;
				tab->precision++;
			}
		}
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, &tab->pad, 1);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		if (n || tab->pad == ' ')
			tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		if (tab->dot && tab->precision < 0 && !n)
			return ;
		tab->total += ft_print_unsigned_number(n, base);
	} 
}*/

void ft_resolve_unsigned_number(t_format *tab, unsigned int n, char *base)
{
	int		len;

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
		if (tab->dot && tab->precision < 0 && !n)
			tab->width++;
		else
			tab->total += ft_print_unsigned_number(n, base);
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if (len > tab->precision && n)
			tab->width -= len;
		else if (n)
			tab->width -= tab->precision;
		else if (!n)
			tab->width -= tab->precision + 1;
		if (n && tab->pad == '0' && tab->dot)
			tab->pad = ' ';
		if (!n && tab->pad == '0')
		{
			tab->pad = ' ';
			if (tab->dot)
			{
				tab->width++;
				tab->precision++;
			}
		}
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, &tab->pad, 1);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		if (tab->dot && tab->precision <= 0 && !n)
			tab->width++;
		else
			tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		if (tab->dot && tab->precision < 0 && !n)
			return ;
		tab->total += ft_print_unsigned_number(n, base);
	} 
}
