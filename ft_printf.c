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
	// else if (c == 'd')
	// 	i += print_integer((int)args);
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
	while (input[i])
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
	printf("\nprintf original: \n");
	printf(" <- %%c, %i printed chars\n", printf("%c", 'a'));
	printf(" <- %%s, %i printed chars\n", printf("%s", s));
	printf(" <- %%p, %i printed chars\n", printf("%p", ptr));
	printf(" <- %%f, %i printed chars\n", printf("%f", 25.5));
	printf(" <- %%i, %i printed chars\n", printf("%i", -27));
	printf(" <- %%u, %i printed chars\n", printf("%u", 27));
	printf(" <- %%x, %i printed chars\n", printf("%x", 424242222));
	printf(" <- %%X, %i printed chars\n", printf("%X", 424242222));
	printf(" <- %%, %i printed chars\n", printf("%%"));

	ft_printf("\nmy ft_printf : \n");
	ft_printf(" <- %%c, %i printed chars\n", ft_printf("%c", 'a'));
	ft_printf(" <- %%s, %i printed chars\n", ft_printf("%s", s));
	ft_printf(" <- %%p, %i printed chars\n", ft_printf("%p", ptr));
	ft_printf(" <- %%f, %i printed chars\n", ft_printf("%f", 25.5));
	ft_printf(" <- %%i, %i printed chars\n", ft_printf("%i", -27));
	ft_printf(" <- %%u, %i printed chars\n", ft_printf("%u", 27));
	ft_printf(" <- %%x, %i printed chars\n", ft_printf("%x", 424242222));
	ft_printf(" <- %%X, %i printed chars\n", ft_printf("%X", 424242222));
	ft_printf(" <- %%, %i printed chars\n", ft_printf("%%"));
}
