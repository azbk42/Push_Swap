/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:59 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/10 18:41:51 by emauduit         ###   ########.fr       */
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
        printf("a = %d, b = %d, c = %d\n", a, b, c);
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
