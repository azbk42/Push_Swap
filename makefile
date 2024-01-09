NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = ./Libft/libft.a
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	@printf "\e[32mPush Swap OK\e[0m\n"
	
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 1>/dev/null
	@$(CC) $(CFLAGS) -lm $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 

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
