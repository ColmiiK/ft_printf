NAME = libftprintf.a
SOURCES = \
	ft_printf.c \
	aux_functions.c \
	print_char.c \
	print_hex_lower.c \
	print_hex_upper.c \
	print_integer.c \
	print_pointer.c \
	print_string.c \
	print_unsigned.c \
	
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re