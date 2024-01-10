#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

# include "../Libft/libft.h"

#define INT_MIN -2147483648
#define INT_MAX  2147483647

// define error
#define DOUBLE_ERROR "Error: double number"
#define NO_DIGIT_ERROR "Error: non digit number find"
#define INT_MAX_MIN_ERROR "Error: number is more than INT_MAX or less than INT_MIN"

// algo 3 numbers

bool is_sort(t_list **stack);
void algo_3_number(t_list **stack_a);


// check des erreurs de parsing
int atoi_parsing(char *str, int *index, t_list *stack_a);
bool check_double(t_list *stack_a, int nb);
void	display_error(const char *message, t_list *stack_a);
bool check_empty_arg(char **av);

// free stack
void free_stack(t_list *stack);

// initialisation des stacks
t_list *create_stack_a(t_list *stack_a, int number);

void start_push_swap(char **av);
void print_stacks(t_list *stack_a, t_list *stack_b); 

// sort_functions:
void swap_sa_sb(t_list **stack, char c);
void swap_ss(t_list **stack_a, t_list **stack_b);
void push_b(t_list **stack_a, t_list **stack_b);
void push_a(t_list **stack_a, t_list **stack_b);
void shift_ra_rb(t_list **stack, char c);
void shift_rr(t_list **stack_a, t_list **stack_b);
void shift_rra_rrb(t_list **stack, char c);
void shift_rrr(t_list **stack_a, t_list **stack_b);
#endif