/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:03 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:04 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_unsigned_number(unsigned long n, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base)
		+ ft_print_unsigned_number(n % len, base));
}

static void	ft_resolve_alternate_hex_dash(t_format *tab, long n,
										char *base, char *code)
{
	int	len;

	len = digit_count(n, 16);
	tab->total += write(STDOUT_FILENO, code, 2);
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

static void	ft_resolve_alternate_hex_width(t_format *tab, long n,
										char *base, char *code)
{
	int	len;

	len = digit_count(n, 16);
	if (len > tab->precision)
		tab->width -= len;
	else
		tab->width -= tab->precision;
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (n)
		tab->total += write(STDOUT_FILENO, code, 2);
	tab->precision -= len - 1;
	while (--tab->precision > 0)
		tab->total += write(STDOUT_FILENO, "0", 1);
	tab->total += ft_print_unsigned_number(n, base);
}

void	ft_resolve_alternate_hex(t_format *tab, long n, char *base, char *code)
{
	int	len;

	len = digit_count(n, 16);
	tab->width -= 2;
	if (tab->dash)
		ft_resolve_alternate_hex_dash(tab, n, base, code);
	else if (tab->width)
		ft_resolve_alternate_hex_width(tab, n, base, code);
	else
	{
		if (n)
			tab->total += write(STDOUT_FILENO, code, 2);
		tab->precision -= len - 1;
		while (--tab->precision > 0)
			tab->total += write(STDOUT_FILENO, "0", 1);
		tab->total += ft_print_unsigned_number(n, base);
	}
}
