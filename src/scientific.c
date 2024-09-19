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

static void ft_print_scientific(t_format * tab, double num, int precision, char c)
{
    int exponent = 0;
    double normalized;

    // Handle the sign
    if (num < 0)
    {
		tab->width--;
        tab->total += write(1, "-", 1);
        num = -num;
    }

    // Normalize the number to scientific form (1 <= number < 10)
    normalized = num;
    while (normalized >= 10.0)
    {
        normalized /= 10.0;
        exponent++;
    }
    while (normalized > 0 && normalized < 1.0)
    {
        normalized *= 10.0;
        exponent--;
    }

    // Print the normalized number up to the given precision
    int int_part = (int)normalized;
    double frac_part = normalized - int_part;

    // Print integer part
	tab->total += ft_print_number(int_part, "0123456789");

    // Print decimal point
    tab->total += write(1, ".", 1);

    // Print fractional part with given precision
    for (int i = 0; i < precision; i++)
    {
        frac_part *= 10.0;
        int digit = (int)frac_part;
        char c = '0' + digit;
        tab->total += write(1, &c, 1);
        frac_part -= digit;
    }

    // Print the 'e' and exponent part in the form +eXX or -eXX
    tab->total += write(1, &c, 1);
    if (exponent >= 0)
        tab->total += write(1, "+", 1);
    else
    {
        tab->total += write(1, "-", 1);
        exponent = -exponent;
    }

    // Print the exponent with two digits (like %02d)
    if (exponent < 10)
		tab->total += write(1, "0", 1);
	tab->total += ft_print_number(exponent, "0123456789");
}

void ft_resolve_scientific(t_format *tab, double n, char c)
{
	if (tab->sign && n >= 0)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (tab->dash)
	{
		if (tab->dot)
			ft_print_scientific(tab, n, tab->precision, c);
		else
		 	ft_print_scientific(tab, n, 6, c);
		tab->width -= 12 - 2;
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		tab->width -= 12 - 2;
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		if (tab->dot)
			ft_print_scientific(tab, n, tab->precision, c);
		else
		 	ft_print_scientific(tab, n, 6, c);
	}
	else
	{
		if (tab->dot)
			ft_print_scientific(tab, n, tab->precision, c);
		else
			ft_print_scientific(tab, n, 6, c);
	}
}

