/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:51:03 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/18 19:20:51 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_count(t_data *count)
{
	while (count->ra > 0 && count->rb > 0)
	{
		count->rr++;
		count->ra--;
		count->rb--;
	}
	while (count->rra > 0 && count->rrb > 0)
	{
		count->rrr++;
		count->rra--;
		count->rrb--;
	}
}

void	count_final_operation(t_list **stack_a, t_list **stack_b, t_data *count)
{
	count->rrb = 0;
	count->rra = 0;
	count->rr = 0;
	count->rrr = 0;
	count->ra = find_position(*stack_a, count->cheapest);
	if (count->ra > ft_lstsize(*stack_a) / 2)
	{
		count->rra = ft_lstsize(*stack_a) - count->ra;
		count->ra = 0;
	}
	count->rb = find_position(*stack_b, count->target);
	if (count->rb > ft_lstsize(*stack_b) / 2)
	{
		count->rrb = ft_lstsize(*stack_b) - count->rb;
		count->rb = 0;
	}
	final_count(count);
}

void	moove_cheapest(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (data->rr--)
		shift_rr(stack_a, stack_b);
	while (data->rrr--)
		shift_rrr(stack_a, stack_b);
	while (data->ra--)
		shift_ra_rb(stack_a, 'a');
	while (data->rb--)
		shift_ra_rb(stack_b, 'b');
	while (data->rra--)
		shift_rra_rrb(stack_a, 'a');
	while (data->rrb--)
		shift_rra_rrb(stack_b, 'b');
	push_b(stack_a, stack_b);
}

void	init_final_algo(t_list **stack_a, t_list **stack_b)
{
	t_data	moove;

	if (!*stack_a)
		return ;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		moove.cheapest = find_cheapest(stack_a, stack_b);
		moove.target = find_final_target(*stack_b, moove.cheapest);
		count_final_operation(stack_a, stack_b, &moove);
		moove_cheapest(stack_a, stack_b, &moove);
	}
	algo_3_numbers(stack_a);
	algo_4_5_numbers(stack_a, stack_b);
}
