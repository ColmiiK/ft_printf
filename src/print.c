#include "../include/ft_printf.h"
#include <unistd.h>

int	ft_print_char(char c)
{
	size_t total;

	total = 0;
	total += write(STDOUT_FILENO, &c, 1);
	return (total);
}

int	ft_print_string(char *str)
{
	size_t total;

	total = 0;
	if (!str)
		str = "(null)";
	while (*str)
		total += write(STDOUT_FILENO, str++, 1);
	return (total);
}

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

int	ft_print_unsigned_number(unsigned long n, char *base)
{

	size_t len;

	len = ft_strlen(base);
	if (len == 16)
		return (ft_print_unsigned_number((unsigned int)n, base));
	if (n / len == 0)
		return (write(1, &base[n % len], 1));
	return (ft_print_unsigned_number(n / len, base) + ft_print_unsigned_number(n % len, base));
}

int	ft_print_float(int n)
{
	(void)n;
	return 0;
}
