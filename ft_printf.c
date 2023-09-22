/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:27:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/22 15:52:22 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	validate_type(char c, void *args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += print_char((char)args);
	else if (c == 's')
		i += print_string((char *)args);
	// else if (c == 'p')
	// 	i += print_pointer(args);
	else if (c == 'd')
		i += print_integer((int)args);
	else if (c == 'i')
		i += print_integer((int)args);
	else if (c == 'u')
		i += print_unsigned((unsigned int)args);
	else if (c == 'x')
		i += print_hex_lower((int)args);
	else if (c == 'X')
		i += print_hex_upper((int)args);
	else if (c == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(char const *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	total;

	i = 0;
	total = 0;
	va_start(args, input);
	while (input)
	{
		if (input[i] == '%')
		{
			i++;
			total += validate_type(input[i], va_arg(args, void *));
		}
		else
			total += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	char	*s;
	char	*ptr;

	s = "lorem ipsum";
	ptr = 0;
	printf("c: %c\n", 'a');
	printf("s: %s\n", s);
	printf("p: %p\n", ptr);
	printf("d(f): %f\n", 25.5);
	printf("i: %i\n", -27);
	printf("u: %u\n", 27);
	printf("x: %x\n", 27);
	printf("X: %X\n", 27);
	printf("%%\n");

	ft_printf("c: %c\n", 'a');
	ft_printf("s: %s\n", s);
	ft_printf("p: %p\n", ptr);
	ft_printf("d(f): %f\n", 25.5);
	ft_printf("i: %i\n", -27);
	ft_printf("u: %u\n", 27);
	ft_printf("x: %x\n", 27);
	ft_printf("X: %X\n", 27);
	ft_printf("%%\n");
}
