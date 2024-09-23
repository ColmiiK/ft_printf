/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:32:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_resolve_number_else(t_format *tab, long n, char *base)
{
	tab->total += ft_print_number(n, base);
}

void	ft_resolve_number(t_format *tab, long n, char *base)
{
	ft_resolve_number_else(tab, n, base);
}
