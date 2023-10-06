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



// sort_functions:

void sort_sa_sb(t_list **stack, char c);
void sort_ss(t_list **stack_a, t_list **stack_b);
void push_b(t_list **stack_a, t_list **stack_b);
void push_a(t_list **stack_a, t_list **stack_b);
void shift_ra_rb(t_list **stack, char c);
void shift_rr(t_list **stack_a, t_list **stack_b);
void shift_rra_rrb(t_list **stack, char c);
void shift_rrr(t_list **stack_a, t_list **stack_b);
#endif