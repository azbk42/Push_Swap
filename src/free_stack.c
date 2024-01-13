/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:06:46 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/13 17:07:09 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
