#include "../include/ft_printf.h"
#include <unistd.h>

static int	ft_print_unsigned_number(unsigned long n, char *base)
{
	size_t len;

	len = ft_strlen(base);
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base) + ft_print_unsigned_number(n % len, base));
}

// Field minimum width, left justify
void ft_resolve_pointer(t_format *tab, long n, char *base)
{
	if (!n)
		ft_resolve_string(tab, "(nil)");
	else if (tab->dash)
	{
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->total += ft_print_unsigned_number(n, base);
		if (n == -1)
			tab->width -= 16 + 2;
		tab->width -= digit_count(n, 16) + 2;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
	}
	else if (tab->width)
	{
		if (n == -1)
			tab->width -= 16 + 2;
		tab->width -= digit_count(n, 16) + 2;
		while (--tab->width >= 0)
			tab->total += write(STDOUT_FILENO, " ", 1);
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->total += ft_print_unsigned_number(n, base);
	}
	else
	{
		tab->total += write(STDOUT_FILENO, "0x", 2);
		tab->total += ft_print_unsigned_number(n, base);
	}
}
