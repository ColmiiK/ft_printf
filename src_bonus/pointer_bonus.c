/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:33 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:34 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static int	ft_print_unsigned_number(unsigned long n, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base)
		+ ft_print_unsigned_number(n % len, base));
}

static void	ft_resolve_pointer_dash(t_format *tab, long n, char *base)
{
	tab->total += write(STDOUT_FILENO, "0x", 2);
	tab->total += ft_print_unsigned_number(n, base);
	if (n == -1)
		tab->width -= 16 + 2;
	tab->width -= digit_count(n, 16) + 2;
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
}

void	ft_resolve_pointer(t_format *tab, long n, char *base)
{
	if (!n)
		ft_resolve_string(tab, "(nil)");
	else if (tab->dash)
		ft_resolve_pointer_dash(tab, n, base);
	else if (tab->width)
	{
		if (n == -1)
			tab->width -= 16 + 2;
		tab->width -= digit_count(n, 16) + 2;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->total += ft_print_unsigned_number(n, base);
	}
}
