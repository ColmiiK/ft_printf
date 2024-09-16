#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_format
{
	va_list	arg;
	int		width; // total width
	int		precision; //how much precision
	int		padding; //padding
	int		point; // precision
	int		dash; //left justify
	int		length; //length
	int		sign; //
	bool	is_zero; //
	int		percentage; //
	int		space; //
	int		total; //
}	t_format;

int		ft_printf(const char *input, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_number(long n, char *base);
int		ft_print_unsigned_number(unsigned long n, char *base);
int		ft_print_float(int n);


#endif
