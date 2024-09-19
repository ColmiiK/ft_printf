#Variables

USERNAME = $(shell whoami)
NAME = libftprintf.a
INCLUDE = include
LIBFT = lib/libft
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar rcs

# Colors

DEF_COLOR = $(shell tput sgr0)
GRAY = $(shell tput setaf 0)
RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
BLUE = $(shell tput setaf 4)
MAGENTA = $(shell tput setaf 5)
CYAN = $(shell tput setaf 6)
WHITE = $(shell tput setaf 7)

#Sources
	
SRC_FILES = ft_printf char string number unsigned_number pointer octal alternate_hex scientific float smart

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists

###

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJ)
			@make -j -C $(LIBFT)
			@$(AR) $(NAME) $(OBJ)
			@$(AR) $(LIBFT)/libft.a
			@$(AR) $(NAME) lib/libft/obj/*.o
			@rm -f lib/libft/obj/*.o
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I./$(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR)
			@rm -f $(NAME)
			@rm -rf $(NAME).dSYM
			@make fclean -C $(LIBFT)
			@echo "$(BLUE)$(NAME) executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)$(NAME) recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT)

bonus:		$(OBJ)
			@make -j -C $(LIBFT)
			@$(AR) $(NAME) $(OBJ)
			@$(AR) x $(LIBFT)/libft.a
			@$(AR) $(NAME) lib/libft/obj/*.o
			@rm -f lib/libft/obj/*.o
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
			

.PHONY: all clean fclean re norm bonus
