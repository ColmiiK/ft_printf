#Variables

USERNAME = $(shell whoami)
NAME = libftprintf.a
INCLUDE = include
SRC_DIR = src/
B_SRC_DIR = src_bonus/
OBJ_DIR = obj/
B_OBJ_DIR = obj_bonus/
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
	
SRC_FILES = ft_printf char string number unsigned_number hex pointer utils aux
B_SRC_FILES = ft_printf char string number unsigned_number hex pointer octal alternate_hex scientific float smart utils 

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
B_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix _bonus.c, $(B_SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJ = $(addprefix $(B_OBJ_DIR), $(addsuffix _bonus.o, $(B_SRC_FILES)))
OBJF = .cache_exists

###

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"


bonus:		$(B_OBJ)
			@$(AR) $(NAME) $(B_OBJ)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I./$(INCLUDE) -c $< -o $@

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I./$(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(B_OBJ_DIR)

clean:
			@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
			@rm -f $(NAME)
			@rm -rf $(NAME).dSYM
			@echo "$(BLUE)$(NAME) executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)$(NAME) recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(B_SRC) $(INCLUDE)
			

.PHONY: all clean fclean re norm bonus
