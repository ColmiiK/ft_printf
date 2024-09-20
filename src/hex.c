/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:24 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:25 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_unsigned_number(unsigned int n, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base)
		+ ft_print_unsigned_number(n % len, base));
}

static void	ft_resolve_hex_dash(t_format *tab, long n, char *base, int len)
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

static void	ft_resolve_hex_width(t_format *tab, long n, char *base, int len)
{
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

static void	ft_resolve_hex_else(t_format *tab, long n, char *base, int len)
{
	tab->precision -= len - 1;
	while (--tab->precision > 0)
		tab->total += write(STDOUT_FILENO, "0", 1);
	if (tab->dot && tab->precision < 0 && !n)
		return ;
	tab->total += ft_print_unsigned_number(n, base);
}

void	ft_resolve_hexadecimal(t_format *tab, long n, char *base)
{
	int	len;

	len = digit_count(n, 16);
	if (n == LONG_MAX || (unsigned long)n == ULONG_MAX)
		len = 8;
	if (n == LONG_MIN)
		len = 1;
	if (tab->dash)
		ft_resolve_hex_dash(tab, n, base, len);
	else if (tab->width)
	{
		if (len > tab->precision && n)
			tab->width -= len;
		else if (n)
			tab->width -= tab->precision;
		else if (!n)
			tab->width -= tab->precision + 1;
		ft_resolve_hex_width(tab, n, base, len);
	}
	else
		ft_resolve_hex_else(tab, n, base, len);
}
