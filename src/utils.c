#include "../include/ft_printf.h"

int	ft_print_number(long n, char *base)
{
	size_t len;

	len = ft_strlen(base);
	if (n < 0 && len == 10)
		return (write(1, "-", 1) + ft_print_number(n * -1, base));
	if (n < 0 && len == 16)
		return (ft_print_number((unsigned int)n, base));
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_number(n / len, base) + ft_print_number(n % len, base));
}

bool	ft_is_normal(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

bool	ft_is_alternate(char c)
{
	if (c == 'o' || c == 'e' || c == 'E' || c == 'f' || c == 'g' || c == 'G'
		|| c == 'x' || c == 'X' || c == 'F')
		return (true);
	return (false);
}

void ft_alternate_conversion(t_format *tab, char c)
{
	if (c == 'o')
		ft_resolve_octal(tab, va_arg(tab->arg, int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ft_resolve_alternate_hex(tab, va_arg(tab->arg, long), "0123456789abcdef", "0x");
		else
			ft_resolve_alternate_hex(tab, va_arg(tab->arg, long), "0123456789ABCDEF", "0X");
	}
	else if (c == 'e' || c == 'E')
	{
		if (c == 'e')
			ft_resolve_scientific(tab, va_arg(tab->arg, double), 'e');
		else
			ft_resolve_scientific(tab, va_arg(tab->arg, double), 'E');
	}
	else if (c == 'f' || c == 'F')
		ft_resolve_float(tab, va_arg(tab->arg, double));
	else if (c == 'g' || c == 'G')
	{
		if (c == 'g')
			ft_resolve_smart(tab, va_arg(tab->arg, double), 'g');
		else
			ft_resolve_smart(tab, va_arg(tab->arg, double), 'G');
	}
}

void ft_conversion(t_format *tab, char c)
{
	if (c == 'c')
		ft_resolve_char(tab, va_arg(tab->arg, int));
	else if (c == 's')
		ft_resolve_string(tab, va_arg(tab->arg, char *));
	else if (c == 'd' || c == 'i')
		ft_resolve_number(tab, va_arg(tab->arg, int), "0123456789");
	else if (c == 'u')
		ft_resolve_unsigned_number(tab, va_arg(tab->arg, int), "0123456789");
	else if (c == 'x')
		ft_resolve_hexadecimal(tab, va_arg(tab->arg, long), "0123456789abcdef");
	else if (c == 'X')
		ft_resolve_hexadecimal(tab, va_arg(tab->arg, long), "0123456789ABCDEF");
	else if (c == 'p')
		ft_resolve_pointer(tab, va_arg(tab->arg, long), "0123456789abcdef");
	else if (c == '%')
		tab->total += write(STDOUT_FILENO, "%", 1);
}
