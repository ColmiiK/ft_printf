#include "../include/ft_printf.h"

static int	ft_print_string(char *str, int index)
{
	int	total;

	total = 0;
	while (*str && total < index)
		total += write(STDOUT_FILENO, str++, 1);
	return (total);
}

static void	ft_resolve_string_dash(t_format *tab, char *str)
{
	if (tab->dot)
		tab->total += ft_print_string(str, tab->precision);
	else
		tab->total += ft_print_string(str, ft_strlen(str));
	if (tab->dot && tab->precision < (int)ft_strlen(str))
		tab->width -= tab->precision;
	else
		tab->width -= ft_strlen(str);
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
}

static void	ft_resolve_string_width(t_format *tab, char *str)
{
	if (tab->dot && tab->precision < (int)ft_strlen(str))
		tab->width -= tab->precision;
	else
		tab->width -= ft_strlen(str);
	while (--tab->width >= 0)
		tab->total += write(STDOUT_FILENO, " ", 1);
	if (tab->dot)
		tab->total += ft_print_string(str, tab->precision);
	else
		tab->total += ft_print_string(str, ft_strlen(str));
}

void	ft_resolve_string(t_format *tab, char *str)
{
	if (!str)
	{
		str = "(null)";
		if (tab->precision < 6)
			tab->precision = 0;
	}
	if (tab->dash)
		ft_resolve_string_dash(tab, str);
	else if (tab->width)
		ft_resolve_string_width(tab, str);
	else
	{
		if (tab->dot)
			tab->total += ft_print_string(str, tab->precision);
		else
			tab->total += ft_print_string(str, ft_strlen(str));
	}
}
