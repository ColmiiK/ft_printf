NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c\
		print_char.c\
		print_string.c\
		print_integer.c\
		print_unsigned.c\
		print_hex_lower.c\
		print_hex_upper.c\
		print_pointer.c\
		aux_functions.c\

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
$(OBJECTS): $(FILES)
	@gcc $(CFLAGS) -c $(FILES)
clean:
	@rm -f $(OBJECTS)
fclean:
	@rm -f $(NAME) $(OBJECTS)
re: fclean all

.PHONY: re all fclean clean makelibft