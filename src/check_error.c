/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:08:51 by azbk              #+#    #+#             */
/*   Updated: 2024/01/10 18:30:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_error(const char *message, t_list *stack_a)
{
    free_stack(stack_a);
    ft_printf("\n%s\n", message);
    exit(EXIT_FAILURE);
}


bool check_empty_arg(char **av)
{
   int i;

   i = 0;
   while (av[i])
   {
      if (!av[i][0])
         return (false);
      i++;
   }
   return (true);
}

bool check_double(t_list *stack_a, int nb)
{
    t_list *current;

    current = stack_a;

    while (current)
    {
        if (current->content == nb)
            return (true);
        else
            current = current->next;
    }
    return (false);
}
