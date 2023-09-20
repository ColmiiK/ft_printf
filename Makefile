NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FILES = 

BONUS = 

OBJECTS = $(FILES:.c=.o)
BOBJECTS = ${BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
$(OBJECTS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)
clean:
	@rm -f $(OBJECTS)
fclean:
	@rm -f $(NAME) $(OBJECTS)
re: fclean all
bonus:
	@gcc ${FLAGS} -c ${BONUS}
	@ar rcs ${NAME} ${BOBJECTS}
.PHONY: re all fclean clean bonus 