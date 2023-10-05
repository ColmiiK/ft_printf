/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:54 by alvega-g          #+#    #+#             */
/*   Updated: 2023/10/05 13:59:23 by alvega-g         ###   ########.fr       */
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

int	print_pointer(void *ptr)
{
	unsigned long long	address;
	int					total;

	address = (unsigned long long)ptr;
	total = 1;
	print_string("0x");
	total += hex_long("0123456789abcdef", address, total);
	return (total);
}
