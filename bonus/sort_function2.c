/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:26:59 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/19 11:34:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	shift_rra_rrb(t_list **stack, char c)
{
	t_list	*current;
	t_list	*tmp_last;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current->next->next)
		current = current->next;
	tmp_last = current->next;
	tmp_last->next = *stack;
	current->next = NULL;
	*stack = tmp_last;
	if (c == 'r')
		ft_printf("rrr\n");
	else if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	shift_rrr(t_list **stack_a, t_list **stack_b)
{
	shift_rra_rrb(stack_a, '0');
	shift_rra_rrb(stack_b, '0');
}

void	shift_rr(t_list **stack_a, t_list **stack_b)
{
	shift_ra_rb(stack_a, '0');
	shift_ra_rb(stack_b, '0');
}

void	shift_ra_rb(t_list **stack, char c)
{
	t_list	*current;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	first = *stack;
	while (current->next != NULL)
		current = current->next;
	*stack = first->next;
	first->next = NULL;
	current->next = first;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else if (c == 's')
		ft_printf("rr\n");
}
