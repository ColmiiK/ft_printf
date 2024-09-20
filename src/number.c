/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_resolve_number_dash(t_format *tab, long n,
									char *base, bool *is_negative)
{
	int	len;

	len = digit_count(n, 10);
	if (len > tab->precision)
		tab->width -= len;
	else
		tab->width -= tab->precision;
	tab->precision -= len - 1;
	if (*is_negative)
		tab->width--;
	if (tab->sign && !*is_negative)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space && !*is_negative)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (*is_negative)
		tab->total += write(STDOUT_FILENO, "-", 1);
	while (--tab->precision > 0)
		tab->total += write(STDOUT_FILENO, "0", 1);
	if (tab->dot && tab->precision < 0 && !n)
		tab->width++;
	else
		tab->total += ft_print_number(n, base);
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
}

static void	ft_resolve_number_width_aux(t_format *tab, long n,
										int len, bool *is_negative)
{
	if (len > tab->precision && n)
		tab->width -= len;
	else if (n)
		tab->width -= tab->precision;
	else if (!n)
		tab->width -= tab->precision + 1;
	if (*is_negative)
		tab->width--;
	if (tab->pad == '0' && *is_negative && !tab->dot)
	{
		tab->total += write(STDOUT_FILENO, "-", 1);
		*is_negative = false;
	}
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
}

static void	ft_resolve_number_width(t_format *tab, long n,
									char *base, bool *is_negative)
{
	int	len;

	len = digit_count(n, 10);
	if ((tab->space || tab->sign) && !*is_negative)
		tab->width--;
	ft_resolve_number_width_aux(tab, n, len, is_negative);
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, &tab->pad, 1);
	tab->precision -= len - 1;
	if (tab->sign && !*is_negative)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space && !*is_negative)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (*is_negative)
		tab->total += write(STDOUT_FILENO, "-", 1);
	while (--tab->precision > 0)
		tab->total += write(STDOUT_FILENO, "0", 1);
	if (tab->dot && tab->precision <= 0 && !n)
		tab->width++;
	else
		tab->total += ft_print_number(n, base);
}

static void	ft_resolve_number_else(t_format *tab, long n,
									char *base, bool *is_negative)
{
	int	len;

	len = digit_count(n, 10);
	if (tab->sign && !*is_negative)
		tab->total += write(STDOUT_FILENO, "+", 1);
	else if (tab->space && !*is_negative)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (*is_negative)
		tab->total += write(STDOUT_FILENO, "-", 1);
	tab->precision -= len - 1;
	while (--tab->precision > 0)
		tab->total += write(STDOUT_FILENO, "0", 1);
	if (tab->dot && tab->precision < 0 && !n)
		return ;
	tab->total += ft_print_number(n, base);
}

void	ft_resolve_number(t_format *tab, long n, char *base)
{
	bool	is_negative;

	is_negative = false;
	if (n < 0)
	{
		is_negative = true;
		n *= -1;
	}
	if (tab->dash)
		ft_resolve_number_dash(tab, n, base, &is_negative);
	else if (tab->width)
		ft_resolve_number_width(tab, n, base, &is_negative);
	else
	{
		if ((tab->space || tab->sign) && !is_negative)
			tab->width--;
		ft_resolve_number_else(tab, n, base, &is_negative);
	}
}
