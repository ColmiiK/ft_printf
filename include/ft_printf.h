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
void	ft_resolve_char(t_format *tab);
void	ft_resolve_string(t_format *tab, char *str);
void	ft_resolve_number(t_format *tab, char *base);
void	ft_resolve_unsigned_number(t_format *tab, char *base);
void	ft_resolve_float(t_format *tab);
void	ft_resolve_pointer(t_format *tab, char *base);
void	ft_resolve_octal(t_format *tab);
void	ft_resolve_alternate_hex(t_format *tab, char *base);
void	ft_resolve_alternate_float(t_format *tab, char c);

#endif
