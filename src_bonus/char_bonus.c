/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:08 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:15 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static int	ft_print_char(char c)
{
	size_t	total;

	total = 0;
	total += write(STDOUT_FILENO, &c, 1);
	return (total);
}

void	ft_resolve_char(t_format *tab, char c)
{
	if (tab->dash)
	{
		tab->total += ft_print_char(c);
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		while (--tab->width > 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->total += ft_print_char(c);
	}
	else
		tab->total += ft_print_char(c);
}
