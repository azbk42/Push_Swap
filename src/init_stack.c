/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:31:52 by azbk              #+#    #+#             */
/*   Updated: 2024/01/10 18:38:15 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(t_list *stack)
{
    t_list *current;
    t_list *next;

    current = stack;
    while (current)
    {
        next = current->next;  
        free(current);
        current = next;
    }
}


static t_list	*setup_stack(char **av, t_list *stack_a)
{
	int	result;
	int	index;

	index = 2;
	result = 0;
	if (av[2])
	{
		while (av[index])
		{
			av[1] = ft_strjoin(av[1], " ");
			av[1] = ft_strjoin(av[1], av[index++]);
		}
	}
	index = 0;
	while (av[1][index])
	{
		result = atoi_parsing(av[1], &index, stack_a);
		if (check_double(stack_a, result))
			return (display_error(DOUBLE_ERROR, stack_a), NULL);
		stack_a = create_stack_a(stack_a, result);
	}
	return (stack_a);
}

void	start_push_swap(char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_empty_arg(av))
		display_error("\nEmpty argument\n", stack_a);
	stack_a = setup_stack(av, stack_a);
	if (!stack_a)
		return ;
	//printf("\n");
	//print_stacks(stack_a, stack_b);
	// if (is_sort(&stack_a))
	// 	printf("IS SORT \n");
	algo_3_number(&stack_a);
	//print_stacks(stack_a, stack_b);
}

t_list	*create_stack_a(t_list *stack_a, int number)
{
	t_list	*new;

	new = ft_lstnew(number);
	if (!new)
		return (NULL);
	ft_lstadd_back(&stack_a, new);
	return (stack_a);
}
