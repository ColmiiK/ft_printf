#include "../include/ft_printf.h"

static int	ft_print_string(char *str)
{
	size_t total;

	total = 0;
	if (!str)
		str = "(null)";
	while (*str)
		total += write(STDOUT_FILENO, str++, 1);
	return (total);
}

// String only accepts field minimum width and left justify
void ft_resolve_string(t_format *tab, char *str)
{
	if (tab->dash)
	{
		tab->total += ft_print_string(str);
		tab->width -= ft_strlen(str) - 1;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		tab->width -= ft_strlen(str) - 1;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->total += ft_print_string(str);
	}
	else
		tab->total += ft_print_string(str);
}

