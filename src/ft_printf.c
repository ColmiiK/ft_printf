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
		tab->total += ft_print_number(va_arg(tab->arg, int), "01234567");
	else if (c == 'x' || c == 'X')
		tab->total += ft_print_number(va_arg(tab->arg, long), "0123456789abcdef");
	else if (c == 'e' || c == 'E')
		tab->total += ft_print_float(va_arg(tab->arg, int));
	else if (c == 'f')
		tab->total += ft_print_float(va_arg(tab->arg, int));
	else if (c == 'g' || c == 'G')
		tab->total += ft_print_float(va_arg(tab->arg, int));
}

// cspdiuxX%
void ft_conversion(t_format *tab, char c)
{
	if (c == 'c')
		tab->total += ft_print_char(va_arg(tab->arg, int));
	else if (c == 's')
		tab->total += ft_print_string(va_arg(tab->arg, char *));
	else if (c == 'd' || c == 'i')
		tab->total += ft_print_number(va_arg(tab->arg, int), "0123456789");
	else if (c == 'u')
		tab->total += ft_print_unsigned_number(va_arg(tab->arg, int), "0123456789");
	else if (c == 'x' || c == 'X')
		tab->total += ft_print_number(va_arg(tab->arg, long), "0123456789abcdef");
	else if (c == 'p')
		tab->total += ft_print_number(va_arg(tab->arg, long), "0123456789abcdef");
	else if (c == '%')
		tab->total += ft_print_char('%');
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
