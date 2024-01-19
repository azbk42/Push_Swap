/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:30 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/19 11:36:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/libft.h"

# define DOUBLE_ERROR "Error: double number"
# define NO_DIGIT_ERROR "Error: non digit number find"
# define INT_MAX_MIN_ERROR \
	"Error: number is more than INT_MAX \
							or less than INT_MIN"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// init

void	start_push_swap(char **av);
void	init_bonus(t_list *stack_a, t_list *stack_b);

// check parsing error

int		atoi_parsing(char **str, int *index, t_list *stack_a);
bool	check_double(t_list *stack_a);
bool	check_empty_arg(char **av);
bool	is_sort(t_list **stack);
void	display_error(char *message, t_list *stack_a, char **av);

// free stack
void	free_stack(t_list *stack);

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