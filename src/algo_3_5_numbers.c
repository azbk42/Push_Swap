/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_5_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:59 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/13 19:18:20 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool is_sort(t_list **stack)
{
    t_list *current;

    if (*stack)
    {
        current = *stack;
        while(current->next)
        {
            if (current->content > current->next->content)
                return (false);
            current = current->next;
        }    
    }
    return (true);
}

void algo_3_number(t_list **stack_a)
{
    int a;
    int b;
    int c;
    while (!is_sort(stack_a))
    {
        a = (*stack_a)->content;
        b = (*stack_a)->next->content;
        c = (*stack_a)->next->next->content;
        if (a > b && b < c && a < c)
            swap_sa_sb(stack_a, 'a');
        else if (c < b && c < a && a < b)
            shift_rra_rrb(stack_a, 'a');
        else if (c < b && c < a && a > b)
            shift_ra_rb(stack_a, 'a');
        else if (a > c && b < c)
            shift_ra_rb(stack_a, 'a');
        else if (a < b && b > c)
            swap_sa_sb(stack_a, 'a');
    }
}

void algo_4_5_numbers(t_list **stack_a, t_list **stack_b)
{
    int target;
    
    if (!stack_a)
        return ;
    push_b(stack_a, stack_b);
    if (ft_lstsize(*stack_a) == 4)
        push_b(stack_a, stack_b);
    algo_3_number(stack_a);
    if (*stack_b && (*stack_b)->next)
        if ((*stack_b)->content < (*stack_b)->next->content)
            swap_sa_sb(stack_b, 'b');
    while (ft_lstsize(*stack_b) > 0)
    {
        target = find_target(*stack_a, (*stack_b)->content);
        while ((*stack_a)->content != target)
        {
            if (find_place(*stack_a, target) <= ft_lstsize(*stack_a))
                shift_rra_rrb(stack_a, 'a');
            else
                shift_ra_rb(stack_a, 'a');
        }
        push_a(stack_a, stack_b);
    }
    while ((*stack_a)->content != find_min(*stack_a))
    {
        if (find_place(*stack_a,find_min(*stack_a)) <  ft_lstsize(*stack_a))
            shift_rra_rrb(stack_a, 'a');
        else
            shift_ra_rb(stack_a, 'a');
    }
}
