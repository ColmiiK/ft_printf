#include "../include/ft_printf.h"

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
void ft_resolve_number(t_format *tab, int n, char *base)
{
	int		len;
	bool is_negative;

	is_negative = false;
	if (n < 0)
	{
		is_negative = true;
		n *= -1;
	}
	len = digit_count(n, 10);
	if (tab->dash)
	{
		if ((tab->space || tab->sign) && !is_negative)
			tab->width--;
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		tab->precision -= len - 1;
		if (is_negative)
			tab->width--;
		if (tab->sign && !is_negative)
			tab->total += write(STDOUT_FILENO, "+", 1);
		else if (tab->space && !is_negative)
			tab->total += write(STDOUT_FILENO, " ", 1);
		if (is_negative)
			tab->total += write(STDOUT_FILENO, "-", 1);
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, base);
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if ((tab->space || tab->sign) && !is_negative)
			tab->width--;
		if (len > tab->precision)
			tab->width -= len;
		else
			tab->width -= tab->precision;
		if (is_negative)
			tab->width--;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->precision -= len - 1;
		if (tab->sign && !is_negative)
			tab->total += write(STDOUT_FILENO, "+", 1);
		else if (tab->space && !is_negative)
			tab->total += write(STDOUT_FILENO, " ", 1);
		if (is_negative)
			tab->total += write(STDOUT_FILENO, "-", 1);
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, base);
	}
	else
	{
		if (tab->sign && !is_negative)
			tab->total += write(STDOUT_FILENO, "+", 1);
		else if (tab->space && !is_negative)
			tab->total += write(STDOUT_FILENO, " ", 1);
		if (is_negative)
			tab->total += write(STDOUT_FILENO, "-", 1);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, base);
	} 
}

