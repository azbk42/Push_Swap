/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:51:03 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/18 19:26:19 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_to_find_cheapest(t_list **stack_a, t_list **stack_b,
		int content, int target)
{
	t_data	count;

	count.rrb = 0;
	count.rra = 0;
	count.rr = 0;
	count.rrr = 0;
	count.ra = find_position(*stack_a, content);
	if (count.ra > ft_lstsize(*stack_a) / 2)
	{
		count.rra = ft_lstsize(*stack_a) - count.ra;
		count.ra = 0;
	}
	count.rb = find_position(*stack_b, target);
	if (count.rb > ft_lstsize(*stack_b) / 2)
	{
		count.rrb = ft_lstsize(*stack_b) - count.rb;
		count.rb = 0;
	}
	final_count(&count);
	count.count = count.rra + count.rrb + count.ra + count.rb + count.rr
		+ count.rrr;
	return (count.count);
}

int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		cheapest;
	int		target;

	current = *stack_a;
	while (current)
	{
		target = find_final_target((*stack_b), current->content);
		current->count_operation = count_to_find_cheapest(stack_a, stack_b,
				current->content, target);
		current = current->next;
	}
	current = *stack_a;
	cheapest = current->content;
	target = current->count_operation;
	while (current)
	{
		if (current->count_operation < target)
		{
			target = current->count_operation;
			cheapest = current->content;
		}
		current = current->next;
	}
	return (cheapest);
}
