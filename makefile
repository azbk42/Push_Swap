NAME = push_swap
FLAGS = cc -Wall -Werror -Wextra
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
RM = rm -f
SRCS = main.c parsing.c utils_stack.c sort_function.c
HEADERS = -I includes
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: 
	${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@make --no-print-directory -C includes/libft
	@make --no-print-directory -C includes/ft_printf
	${FLAGS} ${OBJS} ${LIBFT} ${PRINTF} -o $(NAME)

clean: 
	make clean -C includes/libft/
	make clean -C includes/ft_printf/
	$(RM) ${OBJS}

fclean: clean
	make fclean -C includes/libft/
	make fclean -C includes/ft_printf/
	$(RM) ${LIBFT}
	$(RM) ${PRINTF}
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re
