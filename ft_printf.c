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

// int	ft_printf(char const *c, ...)
// {
// 	va_list x;
// 	va_start(x, c);
	
// 	if (c == 'c')
		
// 	if ()
// }



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
