/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:54 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/25 12:03:31 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_ptr(unsigned long address)
{
	char	c;
	int		total;

	total = 0;
	if (address >= 16)
	{
		total += print_hex_ptr(address / 16);
		total += print_hex_ptr(address % 16);
	}
	else
	{
		c = (address % 16) + '0';
		if ((address % 16) > 9)
			c = ((address % 16) + 87);
		ft_putchar_fd(c, 1);
		total++;
	}
	return (total);
}

static int	hex_len(unsigned long address)
{
	int	total;

	total = 0;
	if (address >= 16)
	{
		total += hex_len(address / 16);
		total += hex_len(address % 16);
	}
	else
		total++;
	return (total);
}

int	print_pointer(void *ptr)
{
	long	address;
	int		total;
	int		len;

	address = (unsigned long)ptr;
	total = 0;
	len = hex_len(address) + 2;
	total += print_string("0x");
	total += print_hex_ptr(address);
	return (total);
}
