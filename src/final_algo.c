/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:51:03 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/14 19:31:20 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int count_all_operations(t_list **stack_a, t_list **stack_b, int content, int target)
{
    int pos_content;
    int pos_target;
    int count;

    pos_content = find_position(*stack_a, content);
    if (pos_content > ft_lstsize(*stack_a) / 2)
        pos_content = ft_lstsize(*stack_a) - pos_content;
    pos_target = find_position(*stack_b, target);
    if (pos_target > ft_lstsize(*stack_b) / 2)
        pos_target = ft_lstsize(*stack_b) - pos_target;
    
    count = pos_target + pos_content;
    ft_printf("count = %d\n", count);
    return (count);
    
    
   
    
        
}

int	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		cheapest;
    int     count;
	int		target;

	current = *stack_a;
	while (current)
	{
		target = find_final_target((*stack_b), current->content);
        ft_printf ("target = %d\n", target);
		current->count_operation = count_all_operations(stack_a, stack_b,
				current->content, target);
        current = current->next;
	}
    current = *stack_a;
    cheapest = current->content;
    count = current->count_operation;
    while (current)
    {
        if (current->count_operation < count)
            cheapest = current->content;
        current = current->next;
    }
	return (cheapest);
}

void	init_final_algo(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	int cheapest;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
    print_stacks(*stack_a, *stack_b);
    ft_printf("\n");
	cheapest = find_cheapest(stack_a, stack_b);
    ft_printf("cheapest = %d\n", cheapest);
}
