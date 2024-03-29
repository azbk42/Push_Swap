/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:30:08 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/20 17:47:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_data
{
	int	ra;
	int	rb;
	int	rrb;
	int	rra;
	int	rr;
	int	rrr;
	int	cheapest;
	int	target;
	int	count;
}		t_data;

// check if the list is sort in ascending order
bool	is_sort(t_list **stack);

// algo 3 to 5 numbers
void	algo_3_numbers(t_list **stack_a);
void	init_algo_4_5(t_list **stack_a, t_list **stack_b);
void	algo_4_5_numbers(t_list **stack_a, t_list **stack_b);

// check parsing error

int		atoi_parsing(char **str, int *index, t_list *stack_a);
bool	check_double(t_list *stack_a);
bool	check_empty_arg(char **av);
void	display_error(char *message, t_list *stack_a, char **av);

// free stack
void	free_stack(t_list *stack);

// find_function, min, max, average,

// find the actual position of the target in the list
int		find_position(t_list *stack_a, int target);
int		find_max(t_list *stack);
int		find_min(t_list *stack);
// find the position in the list of the target
int		find_target_a(t_list *stack, int content_b);
int		find_target_b(t_list *stack, int content);

void	start_push_swap(char **av);

// final_algo

int		find_cheapest(t_list **stack_a, t_list **stack_b);
void	init_final_algo(t_list **stack_a, t_list **stack_b);

// count_operation.c
void	final_count(t_data *count);

// sort_functions:
// swap the first 2 element
void	swap_sa_sb(t_list **stack, char c);
void	swap_ss(t_list **stack_a, t_list **stack_b);
// first element of stack A becomes first B
void	push_b(t_list **stack_a, t_list **stack_b);
// first element of stack B becomes first A
void	push_a(t_list **stack_a, t_list **stack_b);
// shift up all elements of stack by 1
void	shift_ra_rb(t_list **stack, char c);
void	shift_rr(t_list **stack_a, t_list **stack_b);
// shift down all elements of stack by 1
void	shift_rra_rrb(t_list **stack, char c);
void	shift_rrr(t_list **stack_a, t_list **stack_b);

#endif