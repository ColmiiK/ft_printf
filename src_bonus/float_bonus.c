/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:17 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:18 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

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

static void	ft_resolve_float_dash(t_format *tab, double n)
{
	int	len;

	len = digit_count((int)n, 10);
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

static void	ft_resolve_float_width(t_format *tab, double n)
{
	int	len;

	len = digit_count((int)n, 10);
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

void	ft_resolve_float(t_format *tab, double n)
{
	if (tab->sign && n >= 0)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (tab->dash)
		ft_resolve_float_dash(tab, n);
	else if (tab->width)
		ft_resolve_float_width(tab, n);
	else
	{
		if (tab->dot)
			tab->total += ft_print_float(n, tab->precision);
		else
			tab->total += ft_print_float(n, 6);
	}
}
