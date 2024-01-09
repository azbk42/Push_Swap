/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:31:52 by azbk              #+#    #+#             */
/*   Updated: 2024/01/08 16:40:53 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static t_list	*setup_stack(char **av, int index, t_list *stack_a)
{
	int	result;

	result = 0;
	if (av[2])
	{
		while (av[index])
		{
			av[1] = ft_strjoin(av[1], " ");
			av[1] = ft_strjoin(av[1], av[index]);
			index++;
		}
	}
	index = 0;
	while (av[1][index])
	{
		result = atoi_parsing(av[1], &index);
		if (check_double(stack_a, result))
			display_error(DOUBLE_ERROR);
		stack_a = create_stack_a(stack_a, result);
	}
	return (stack_a);
}

void	start_push_swap(char **av, t_list *stack_a, t_list *stack_b)
{
	int	index;

	index = 2;
	if (!av[1][0])
		display_error("\nEmpty argument\n");
	else if (!check_empty_arg(av))
		display_error("\nEmpty argument\n");
	stack_a = setup_stack(av, index, stack_a);
	stack_b = create_stack_a(stack_b, 10);
	stack_b = create_stack_a(stack_b, 20);
	stack_b = create_stack_a(stack_b, 30);
	stack_b = create_stack_a(stack_b, 40);
	printf("\n");
	print_stacks(stack_a, stack_b);
	// shift_rra_rrb(&stack_b, 'b');
	// print_stacks(stack_a, stack_b);
}


t_list	*create_stack_a(t_list *stack_a, int number)
{
	t_list	*new;

	new = ft_lstnew(number);
	if (!new)
		return (NULL);
	ft_lstadd_front(&stack_a, new);
	return (stack_a);
}
