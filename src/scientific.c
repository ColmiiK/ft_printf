#include "../include/ft_printf.h"

static int	ft_print_scientific_aux(t_format *tab, double *num,
									int *exponent, double *normalized)
{
	if (*num < 0)
	{
		tab->width--;
		tab->total += write(1, "-", 1);
		*num = -*num;
	}
	*normalized = *num;
	while (*normalized >= 10.0)
	{
		*normalized /= 10.0;
		*exponent = *exponent + 1;
	}
	while (*normalized > 0 && *normalized < 1.0)
	{
		*normalized *= 10.0;
		*exponent = *exponent - 1;
	}
	return ((int)*normalized);
}

static void	ft_print_scientific_aux_exponent(t_format *tab, int exponent)
{
	if (exponent >= 0)
		tab->total += write(1, "+", 1);
	else
	{
		tab->total += write(1, "-", 1);
		exponent = -exponent;
	}
	if (exponent < 10)
		tab->total += write(1, "0", 1);
	tab->total += ft_print_number(exponent, "0123456789");
}

static void	ft_print_scientific(t_format *tab, double num,
								int precision, char c)
{
	int		exponent;
	double	normalized;
	int		int_part;
	double	frac_part;

	exponent = 0;
	int_part = ft_print_scientific_aux(tab, &num, &exponent, &normalized);
	frac_part = normalized - int_part;
	tab->total += ft_print_number(int_part, "0123456789");
	tab->total += write(STDOUT_FILENO, ".", 1);
	while (precision-- > 0)
	{
		frac_part *= 10.0;
		tab->total += ft_print_number((int)frac_part, "0123456789");
		frac_part -= (int)frac_part;
	}
	tab->total += write(STDOUT_FILENO, &c, 1);
	ft_print_scientific_aux_exponent(tab, exponent);
}

static void	ft_resolve_scientific_dash(t_format *tab, double n, char c)
{
	if (tab->dot)
		ft_print_scientific(tab, n, tab->precision, c);
	else
		ft_print_scientific(tab, n, 6, c);
	tab->width -= 12 - 2;
	while (--tab->width > 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
}

void	ft_resolve_scientific(t_format *tab, double n, char c)
{
	if (tab->sign && n >= 0)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (tab->dash)
		ft_resolve_scientific_dash(tab, n, c);
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
