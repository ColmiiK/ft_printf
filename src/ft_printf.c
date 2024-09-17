#include "../include/ft_printf.h"

	/*
	 *
	 *  - -> justificado izquierda, si no está se justifica a la derecha
	 *  0 -> n padding (minimum field width)
	 *  . -> precisión (seguido de número) || si es un float corta o añade ceros
	 *			si hace falta, si es un int añade ceros a la izquierda
	 * ' '-> añade un espacio si el número es positivo
	 *	+ -> printea el signo
	 *	# -> forma alternativa:
	 *			o -> octal (0 + numero en octal)
	 *			x -> hex (0x + numero)
	 *			X -> HEX (0x + numero)
	 *			e -> Siempre muestra punto decimal (e)
	 *			E -> Siempre muestra punto decimal (E)
	 *			f -> Siempre muestra punto decimal
	 *			g -> Siempre muestra punto decimal, no borra ceros
	 *			G -> Siempre muestra punto decimal, no borra ceros
	 *
	 * */


void print_everything(t_format *tab) {
	printf("\nwidth: \t\t%d\n", tab->width);
	printf("precision: \t%d\n", tab->precision);
	printf("padding: \t%d\n", tab->padding);
	printf("point: \t\t%d\n", tab->point);
	printf("dash: \t\t%d\n", tab->dash);
	printf("length: \t%d\n", tab->length);
	printf("sign: \t\t%d\n", tab->sign);
	printf("is zero: \t%d\n", tab->is_zero);
	printf("percentage: \t%d\n", tab->percentage);
	printf("space: \t\t%d\n", tab->space);
	printf("total: \t\t%d\n\n", tab->total);
}

void ft_constructor(t_format *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->padding = 0;
	tab->point = 0;
	tab->dash = 0;
	tab->length = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->percentage = 0;
	tab->space = 0;
	tab->total = 0;
}
bool	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%' || c == '#')
		return (true);
	return (false);
}

// oxXeEfgG
void ft_alternate_conversion(t_format *tab, char c)
{
	if (c == 'o')
		ft_resolve_number(tab, "01234567");
	else if (c == 'x' || c == 'X')
		ft_resolve_number(tab, "0123456789abcdef");
	else if (c == 'e' || c == 'E')
		ft_resolve_float(tab);
	else if (c == 'f')
		ft_resolve_float(tab);
	else if (c == 'g' || c == 'G')
		ft_resolve_float(tab);
}

// cspdiuxX%
void ft_conversion(t_format *tab, char c)
{
	if (c == 'c')
		ft_resolve_char(tab);
	else if (c == 's')
		ft_resolve_string(tab);
	else if (c == 'd' || c == 'i')
		ft_resolve_number(tab, "0123456789");
	else if (c == 'u')
		ft_resolve_unsigned_number(tab, "0123456789");
	else if (c == 'x' || c == 'X')
		ft_resolve_number(tab, "0123456789abcdef");
	else if (c == 'p')
		ft_resolve_number(tab, "0123456789abcdef");
	else if (c == '%')
		ft_resolve_char(tab);
}

int	ft_evaluate(t_format *tab, const char* input)
{
	input++;
	while (!ft_is_conversion(*input))
	{
		if (*input == '-')
		{
			tab->dash = 1;
			input++;
		}
		if (ft_isdigit(*input))
		{
			tab->width = ft_atoi(input);
			while (ft_isdigit(*input))
				input++;
		}
		if (*input == '.')
		{
			input++;
			tab->precision = ft_atoi(input);
			while (ft_isdigit(*input))
				input++;
		}
		if (*input == '+')
		{
			tab->sign = 1;
			input++;
		}
		if (*input == ' ')
		{
			tab->space = 1;
			input++;
		}
	}
	print_everything(tab);
	if (*input == '#')
		return (ft_alternate_conversion(tab, *(++input)), 2);
	else
		return (ft_conversion(tab, *input), 1);
}

int	ft_printf(const char *input, ...)
{
	t_format	tab;

	ft_constructor(&tab);
	va_start(tab.arg, input);
	while (*input)
	{
		if (*input == '%')
			input += ft_evaluate(&tab, input);
		else
			tab.total += write(STDOUT_FILENO, input, 1);
		input++;
	}
	va_end(tab.arg);
	return (tab.total);
}
