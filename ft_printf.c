/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:27:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/25 12:15:55 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	validate_type(char c, va_list args)
{
	unsigned int	i;

	i = 0;
	if (c == 'c')
		i += print_char(va_arg(args, int));
	else if (c == 's')
		i += print_string(va_arg(args, char *));
	else if (c == 'p')
		i += print_pointer(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		i += print_integer(va_arg(args, int));
	else if (c == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		i += print_hex_lower(va_arg(args, int));
	else if (c == 'X')
		i += print_hex_upper(va_arg(args, int));
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
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			total += validate_type(input[i], args);
		}
		else
			total += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (total);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*ptr;

// 	s = "lorem";
// 	ptr = s;
// 	printf("\nprintf original: \n");
// 	printf(" <- %%c, %i printed chars\n", printf("%c", 'a'));
// 	printf(" <- %%s, %i printed chars\n", printf("%s", s));
// 	printf(" <- %%p, %i printed chars\n", printf("%p", ptr));
// 	printf(" <- %%d, %i printed chars\n", printf("%d", 31415));
// 	printf(" <- %%i, %i printed chars\n", printf("%i", -27));
// 	printf(" <- %%u, %i printed chars\n", printf("%u", 27));
// 	printf(" <- %%x, %i printed chars\n", printf("%x", 424242222));
// 	printf(" <- %%X, %i printed chars\n", printf("%X", 424242222));
// 	printf(" <- %%, %i printed chars\n", printf("%%"));

// 	ft_printf("\nmy ft_printf : \n");
// 	ft_printf(" <- %%c, %i printed chars\n", ft_printf("%c", 'a'));
// 	ft_printf(" <- %%s, %i printed chars\n", ft_printf("%s", s));
// 	ft_printf(" <- %%p, %i printed chars\n", ft_printf("%p", ptr));
// 	ft_printf(" <- %%d, %i printed chars\n", ft_printf("%d", 31415));
// 	ft_printf(" <- %%i, %i printed chars\n", ft_printf("%i", -27));
// 	ft_printf(" <- %%u, %i printed chars\n", ft_printf("%u", 27));
// 	ft_printf(" <- %%x, %i printed chars\n", ft_printf("%x", 424242222));
// 	ft_printf(" <- %%X, %i printed chars\n", ft_printf("%X", 424242222));
// 	ft_printf(" <- %%, %i printed chars\n", ft_printf("%%"));
//  }
