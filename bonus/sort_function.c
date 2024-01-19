/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:26:45 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/19 11:34:50 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_sa_sb(t_list **stack, char c)
{
	int		tmp;
	t_list	*current;

	if (*stack == NULL)
		return ;
	current = *stack;
	tmp = current->content;
	current->content = current->next->content;
	current->next->content = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else if (c == 's')
		ft_printf("ss\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_sa_sb(stack_a, '0');
	swap_sa_sb(stack_b, '0');
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (*stack_b == NULL)
		return ;
	current = *stack_b;
	*stack_b = current->next;
	current->next = *stack_a;
	*stack_a = current;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (*stack_a == NULL)
		return ;
	current = *stack_a;
	*stack_a = current->next;
	current->next = *stack_b;
	*stack_b = current;
}
