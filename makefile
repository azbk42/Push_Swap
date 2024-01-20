NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a
SRC_DIR = ./src
SRC := sort_functions/sort_function.c \
		sort_functions/sort_function2.c \
		algo_3_5_numbers.c \
		check_error.c \
		find_min_max.c \
		free_stack.c \
		init_stack.c \
		main.c \
		parsing.c \
		final_algo.c \
		count_operation.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS := $(OBJ:.o=.d)
DEPS += ./Libft/*.d

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
RESET = \033[0m
MAKEFLAGS += --no-print-directory

all: $(NAME) 
	@echo "$(PINK)Push Swap OK$(RESET)"
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 
	@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"

norminette:
	norminette $(SRC_DIR)
	norminette Libft/
	norminette ./includes/

clean:
	@echo "$(CYAN)Removing: $(OBJ) $(OBJ_DIR) $(DEF_COLOR)"
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJ_DIR)
	@rm -f ./Libft/*.d
	@rm -f Libft/GNL/*.d	
	@rm -f Libft/ft_printf/*.d

fclean: clean
	@$(MAKE) -C ./Libft fclean
	@rm -f $(NAME)
	@echo "$(RED)libft.a remove$(DEF_COLOR)"
	@echo "$(RED)$(NAME) remove$(DEF_COLOR)"

re: fclean all

-include $(DEPS)
