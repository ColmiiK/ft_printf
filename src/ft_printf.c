#include "../include/ft_printf.h"

static void	ft_constructor(t_format *tab)
{
	tab->width = 0;
	tab->pad = ' ';
	tab->precision = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->sign = 0;
	tab->space = 0;
}

static void ft_setter(void *arg, int *index)
{
	bool *temp;

	temp = arg;
	*temp = 1;
	*index = *index + 1;
}

static int ft_evaluate_alternate(t_format *tab, const char *input, int i, bool *pound)
{
	if (input[i] == '#')
		ft_setter(pound, &i);
	if (input[i] == '-')
		ft_setter(&tab->dash, &i);
	if (ft_isdigit(input[i]))
	{
		if (input[i] == '0')
			tab->pad = '0';
		tab->width = ft_atoi(input + i);
		while (ft_isdigit(input[i]))
			i++;
	}
	if (input[i] == '.')
	{
		i++;
		tab->dot = true;
		tab->precision = ft_atoi(input + i);
		while (ft_isdigit(input[i]))
			i++;
	}
	if (input[i] == '+')
		ft_setter(&tab->sign, &i);
	if (input[i] == ' ')
		ft_setter(&tab->space, &i);
	return (i);
}

static int	ft_evaluate(t_format *tab, const char* input, int i)
{
	bool	pound;

	pound = false;
	i++;
	while (!ft_is_normal(input[i]) && !ft_is_alternate(input[i]))
		i = ft_evaluate_alternate(tab,  input, i, &pound);
	if (pound && ft_is_alternate(input[i]))
		ft_alternate_conversion(tab, input[i]);
	else 
		ft_conversion(tab, input[i]);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	t_format	tab;
	int i;
	
	tab.total = 0;
	ft_constructor(&tab);
	va_start(tab.arg, input);
	i = -1;
	while (input[++i])
	{
		if (input[i] == '%')
			i = ft_evaluate(&tab, input, i);
		else
			tab.total += write(STDOUT_FILENO, &input[i], 1);
		ft_constructor(&tab);
	}
	va_end(tab.arg);
	return (tab.total);
}
