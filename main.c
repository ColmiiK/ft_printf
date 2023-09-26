#include "ft_printf.h"

int	main(void)
{
	char	*s;
	char	*ptr;

	s = "lorem";
	ptr = s;
	printf("\nprintf original: \n");
	printf(" <- %%c, %i printed chars\n", printf("%c", 'a'));
	printf(" <- %%s, %i printed chars\n", printf("%s", "lorem ipsum dolor sit amet"));
	printf(" <- empty, %i printed chars\n", printf(""));
	printf(" <- %%s, %i printed chars\n", printf("%s", s));
	printf(" <- %%p, %i printed chars\n", printf("%p", ptr));
	printf(" <- %%d, %i printed chars\n", printf("%d", 31415));
	printf(" <- %%i, %i printed chars\n", printf("%i", -27));
	printf(" <- %%u, %i printed chars\n", printf("%u", 27));
	printf(" <- %%x, %i printed chars\n", printf("%x", 424242222));
	printf(" <- %%X, %i printed chars\n", printf("%X", 424242222));
	printf(" <- %%, %i printed chars\n", printf("%%"));

	ft_printf("\nmy ft_printf : \n");
	ft_printf(" <- %%c, %i printed chars\n", ft_printf("%c", 'a'));
	ft_printf(" <- %%s, %i printed chars\n", ft_printf("%s", "lorem ipsum dolor sit amet"));
	ft_printf(" <- empty, %i printed chars\n", ft_printf(""));
	ft_printf(" <- %%s, %i printed chars\n", ft_printf("%s", s));
	ft_printf(" <- %%p, %i printed chars\n", ft_printf("%p", ptr));
	ft_printf(" <- %%d, %i printed chars\n", ft_printf("%d", 31415));
	ft_printf(" <- %%i, %i printed chars\n", ft_printf("%i", -27));
	ft_printf(" <- %%u, %i printed chars\n", ft_printf("%u", 27));
	ft_printf(" <- %%x, %i printed chars\n", ft_printf("%x", 424242222));
	ft_printf(" <- %%X, %i printed chars\n", ft_printf("%X", 424242222));
	ft_printf(" <- %%, %i printed chars\n", ft_printf("%%"));
 }