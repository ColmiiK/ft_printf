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

int	ft_printf(const char *input, ...);

#endif
