/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:31 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:31 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void	ft_resolve_octal_dash(t_format *tab, int n, int len)
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

static void	ft_resolve_octal_width(t_format *tab, int n, int len)
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

void	ft_resolve_octal(t_format *tab, int n)
{
	int		len;

	len = digit_count(n, 8);
	if (!n)
		tab->total += write(STDOUT_FILENO, "0", 1);
	else if (tab->dash)
		ft_resolve_octal_dash(tab, n, len);
	else if (tab->width)
		ft_resolve_octal_width(tab, n, len);
	else
	{
		tab->precision -= len;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_number(n, "01234567");
	}
}
