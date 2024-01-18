/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:08:51 by azbk              #+#    #+#             */
/*   Updated: 2024/01/18 17:52:22 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_error(char *message, t_list *stack_a, char **av)
{
	if (av[2])
		free(av[1]);
	free_stack(stack_a);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

bool	check_empty_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i][0])
			return (false);
		i++;
	}
	return (true);
}

bool	check_double(t_list *stack_a)
{
	t_list	*current;
	t_list	*prev;

	prev = stack_a;
	while (prev->next)
	{
		current = prev->next;
		while (current)
		{
			if (current->content == prev->content)
				return (true);
			else
				current = current->next;
		}
		prev = prev->next;
	}
	return (false);
}
bool	is_sort(t_list **stack)
{
	t_list	*current;

	if (*stack)
	{
		current = *stack;
		while (current->next)
		{
			if (current->content > current->next->content)
				return (false);
			current = current->next;
		}
	}
	return (true);
}
