/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:06:46 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/19 11:35:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
