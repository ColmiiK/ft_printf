/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:56:52 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/22 14:35:49 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*remove_zeroes_and_print(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '0' && i < 8)
		i++;
	ft_putstr_fd(s + i, 1);
	return (&s[i]);
}

int	print_hex_lower(int n)
{
	char	*hex;
	char	res[9];
	int		i;
	int		j;

	hex = "0123456789abcdef";
	i = 7;
	j = 0;
	res[8] = 0;
	while (j < 8)
	{
		res[j] = 0;
		j++;
	}
	j = 0;
	while (j < 8)
	{
		res[i] = hex[n & 0xF];
		n >>= 4;
		i--;
		j++;
	}
	return (ft_strlen(remove_zeroes_and_print(res)));
}
