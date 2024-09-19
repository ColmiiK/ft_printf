#include "../include/ft_printf.h"

void ft_resolve_smart(t_format *tab, double n, char c)
{
	int len;

	len = digit_count((int)n, 10);
	if ((tab->dot && tab->precision < len && len != 1) || (!tab->dot && len > 6))
	{
		if (!tab->dot)
		{
			tab->dot = true;
			tab->precision = 5;
		}
		else
		{
			if (tab->precision == 0)
				tab->precision++;
			tab->width -= tab->precision - 6;
			tab->precision--;
		}
		if (c == 'g')
			ft_resolve_scientific(tab, n, 'e');
		else
			ft_resolve_scientific(tab, n, 'E');
	}
	else
	{
		if (!tab->dot)
		{
			tab->dot = true;
			tab->precision = 6 - len;
		}
		else
			if (len != 1)
				tab->precision -= len;
		ft_resolve_float(tab, n);
	}
}
