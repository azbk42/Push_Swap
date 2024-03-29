/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:51:03 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/20 14:47:38 by emauduit         ###   ########.fr       */
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

static void	moove_cheapest(t_list **stack_a, t_list **stack_b, t_data *data)
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

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d ", current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("_  ");
		ft_printf("    ");
		if (current_b)
		{
			ft_printf("%d", current_b->content);
			current_b = current_b->next;
		}
		else
			ft_printf("_");
		ft_printf("\n");
	}
	ft_printf("A      B\n");
}

static void	count_operation_a_to_b(t_list **stack_a, t_list **stack_b,
		t_data *count)
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
		moove.target = find_target_b(*stack_b, moove.cheapest);
		count_operation_a_to_b(stack_a, stack_b, &moove);
		moove_cheapest(stack_a, stack_b, &moove);
	}
	algo_3_numbers(stack_a);
	algo_4_5_numbers(stack_a, stack_b);
}
