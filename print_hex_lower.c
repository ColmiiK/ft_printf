/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:52 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/25 13:12:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_long(char *base, unsigned long long n, int i)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (n >= len)
	{
		i = hex_long(base, n / len, i);
		ft_putchar_fd(base[n % len], 1);
		i++;
	}
	else if (n < len)
	{
		ft_putchar_fd(base[n], 1);
		i++;
	}
	return (i);
}

int	print_hex_lower(unsigned int n)
{
	int	total;

	total = 0;
	total = hex_long("0123456789abcdef", n, total);
	return (total);
}
