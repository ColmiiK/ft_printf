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

static void	ft_resolve_hex_else(t_format *tab, long n, char *base)
{
	tab->total += ft_print_unsigned_number(n, base);
}

void	ft_resolve_hexadecimal(t_format *tab, long n, char *base)
{
	ft_resolve_hex_else(tab, n, base);
}
