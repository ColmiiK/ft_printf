/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:26:33 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/25 12:07:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_printf(char const *input, ...);
int	print_char(char c);
int	print_integer(int nb);
int	print_string(char *str);
int	print_unsigned(unsigned int nb);
int	print_hex_lower(int n);
int	print_hex_upper(int n);
int	print_pointer(void *ptr);

#endif