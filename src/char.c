#include "../include/ft_printf.h"

static int	ft_print_char(char c)
{
	size_t total;

	total = 0;
	total += write(STDOUT_FILENO, &c, 1);
	return (total);
}


// Char only accepts field minimum width and left justify
void	ft_resolve_char(t_format *tab)
{
	if (tab->dash)
	{
		tab->total += ft_print_char(va_arg(tab->arg, int));
		while (--tab->width != 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		while (--tab->width != 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->total += ft_print_char(va_arg(tab->arg, int));
	}
	else
		tab->total += ft_print_char(va_arg(tab->arg, int));
}

