NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

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

BONUS_DIR = ./bonus
SRC_BONUS := check_error_bonus.c \
			free_stack_bonus.c\
			init_stack_bonus.c \
			main_checker.c \
			parsing_bonus.c \
			sort_function.c \
			sort_function2.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
SRC_BONUS := $(addprefix $(BONUS_DIR)/, $(SRC_BONUS))
OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS := $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)

DEPS := $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
RESET = \033[0m
MAKEFLAGS += --no-print-directory

all: $(NAME) $(BONUS)
	@echo "$(PINK)Push Swap OK$(RESET)"
	@echo "$(PINK)BONUS OK$(RESET)"
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

$(BONUS): $(OBJ_BONUS)
	@$(MAKE) -C ./Libft 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)


.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 

bonus: $(BONUS)
	@echo "$(PINK)BONUS OK$(RESET)"


norminette:
	norminette $(SRC_DIR)
	norminette $(BONUS_DIR)
	norminette Libft/
	norminette ./includes/

clean:
	@echo "$(CYAN)Removing: $(OBJ) $(OBJ_DIR) $(OBJ_DIR_BONUS)$(DEF_COLOR)"
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJ_DIR) 
	@rm -rf $(OBJ_DIR_BONUS)


fclean: clean
	@$(MAKE) -C ./Libft fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "$(RED)libft.a remove$(DEF_COLOR)"
	@echo "$(RED)$(NAME) remove$(DEF_COLOR)"
	@echo "$(RED)$(BONUS) remove$(DEF_COLOR)"

re: fclean all

-include $(DEPS)
