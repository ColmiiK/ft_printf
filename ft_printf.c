/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:27:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/20 16:31:37 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int validate_type(char c, void *args)
{
	int i;

	i = 0;
	if (c == 'c')
		i += ft_putchar((char)args);
	else if (c == 's')
		i += ft_putstr((char *)args);
	else if (c == 'p')

	else if (c == 'f')

	else if (c == 'i')
		i += ft_putnbr((int)args);
	else if (c == 'u')

	else if (c == 'x')

	else if (c == 'X')

	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(char const *input, ...)
{
	va_list args;
	va_start(args, input);
	int i;

	i = 0;
	while (input)
	{
		if (input[i] == '%')
		{
			validate_type(&input[i++], va_arg(args, void *));
		}
		else
			ft_putchar(&input[i]);
		i++;
		
	}
	va_end(args);
	return (i);
}


int main()
{
	char *s = "lorem ipsum";
	char *ptr = 0;

	printf("c: %c\n", 'a');
	printf("s: %s\n", s);
	printf("p: %p\n", ptr);
	printf("d(f): %f\n", 25.5);
	printf("i: %i\n", -27);
	printf("u: %u\n", 27);
	printf("x: %x\n", 27);
	printf("X: %X\n", 27);
	printf("%%\n");
}
