NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFTNAME = libft.a
LIBFTDIR = ./libft
FILES = ft_printf.c\
		print_char.c\
		print_string.c\
		print_integer.c\
		print_unsigned.c\

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
$(OBJECTS): $(FILES)
	@gcc $(CFLAGS) -c $(FILES)
clean:
	@rm -f $(OBJECTS)
	@cd $(LIBFTDIR) && make clean
fclean:
	@rm -f $(NAME) $(OBJECTS)
	@cd $(LIBFTDIR) && make fclean
re: fclean all

.PHONY: re all fclean clean makelibft