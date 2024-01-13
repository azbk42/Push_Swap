/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:47:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/13 19:16:02 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_min(t_list *stack)
{
    int min;
    t_list *current;

    current = stack;
    min = stack->content;
    while (current)
    {
        if (current->content < min)
            min = current->content;
        current = current->next;
    }
    return (min);
}

int find_max(t_list *stack)
{
    int max;
    t_list *current;

    current = stack;
    max = current->content;
    while(current)
    {
        if (current->content > max)
            max = current->content;
        current = current->next;
    }
    return (max);
}
/***
 find the actual place of the target in the list
*/
int find_place(t_list *stack_a, int target)
{
    int place;
    t_list *current;

    current = stack_a;
    place = 0;
    if (current)
    {
        while (current->content != target)
        {
            place++;
            current = current->next;
        }
    }
    return (place);
}

int find_target(t_list *stack, int content_b)
{
    t_list *current;
    int target;

    current = stack;
    target = find_max(stack);
    
    if (content_b > target)
        return (find_min(stack));
    while (current)
    {
        if (current->content < target && current->content > content_b)
            target = current->content;
        current = current->next;
    }
    return (target);
}