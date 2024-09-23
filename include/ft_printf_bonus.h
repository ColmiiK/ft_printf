/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:31:51 by alvega-g          #+#    #+#             */
/*   Updated: 2024/09/20 19:31:56 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_format
{
	va_list	arg; // variadic list
	int		width; // field minimum width
	char	pad; // use space or zero to pad
	int		precision; // how much precision
	bool	dot; // there is precision
	bool	dash; //left justify
	bool	sign; // there is sign
	bool	space; // there is space
	int		total; // total printed chars
}	t_format;

int		ft_printf(const char *input, ...);
void	ft_resolve_char(t_format *tab, char c);
void	ft_resolve_string(t_format *tab, char *str);
void	ft_resolve_number(t_format *tab, long n, char *base);
void	ft_resolve_unsigned_number(t_format *tab, unsigned int n, char *base);
void	ft_resolve_hexadecimal(t_format *tab, long n, char *base);
void	ft_resolve_pointer(t_format *tab, long n, char *base);
void	ft_resolve_octal(t_format *tab, int n);
void	ft_resolve_alternate_hex(t_format *tab, long n, char *base, char *code);
void	ft_resolve_scientific(t_format *tab, double n, char c);
void	ft_resolve_float(t_format *tab, double n);
void	ft_resolve_smart(t_format *tab, double n, char c);

void	ft_alternate_conversion(t_format *tab, char c);
void	ft_conversion(t_format *tab, char c);

bool	ft_is_alternate(char c);
bool	ft_is_normal(char c);
int		digit_count(long n, int base);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);

int		ft_print_number(long n, char *base);

#endif
