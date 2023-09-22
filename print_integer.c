/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:26:00 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/22 11:47:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int nb)
{
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		return (11);
	return (digit_count(nb));
}