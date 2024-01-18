NAME = push_swap

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
		print_stack.c \
		final_algo.c \
		set_position.c \
		count_operation.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJ:.o=.d)

all: $(NAME)
	@printf "\e[32mPush Swap OK\e[0m\n"
		
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 1>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 

norminette:
	norminette $(SRC_DIR)
	norminette Libft/
	norminette ./includes/

clean:
	@$(MAKE) -C ./Libft clean 1>/dev/null
	@rm -rf $(OBJ_DIR)
	@echo "All object files have been removed. (clean)"

fclean: clean
	@$(MAKE) -C ./Libft fclean 1>/dev/null
	@rm -f $(NAME)
	@echo "All executable files and object files have been removed. (fclean)"

re: fclean all

-include $(DEPS)
