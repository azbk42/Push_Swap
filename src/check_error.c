/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:08:51 by azbk              #+#    #+#             */
/*   Updated: 2024/01/08 16:40:58 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_error(const char *message)
{
    ft_printf("\n%s\n\n", message);
    exit(EXIT_FAILURE);
}

bool check_empty_arg(char **av)
{
   int i;

   i = 0;
   while (av[i])
   {
      if (!av[i][0])
         return false;
      i++;
   }
   return true;
}

bool check_double(t_list *stack_a, int nb)
{
    t_list *current;

    current = stack_a;

    while (current)
    {
        if (current->content == nb)
            return true;
        else
            current = current->next;
    }
    return false;
}
