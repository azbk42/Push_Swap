#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"

#define INT_MIN -2147483648
#define INT_MAX  2147483647


int atoi_parsing(char *str, int *index);
bool check_double(t_list *stack_a, int nb);
void start_push_swap(char **av, t_list *stack_a, t_list *stack_b);
void print_stacks(t_list *stack_a, t_list *stack_b); 
t_list *create_stack_a(t_list *stack_a, int number);
void display_error();

#endif