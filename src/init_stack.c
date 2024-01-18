/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:31:52 by azbk              #+#    #+#             */
/*   Updated: 2024/01/18 19:09:53 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*create_stack_a(t_list *stack_a, int number)
{
	t_list	*new;

	new = ft_lstnew(number);
	if (!new)
		return (NULL);
	ft_lstadd_back(&stack_a, new);
	return (stack_a);
}

/**
 * use ft_strjoin if more than 1 str is send to init stack
 */
static char	*join_av1(char **av)
{
	char	*tmp;
	char	*new_str;
	int		index;

	new_str = ft_strdup(av[1]);
	if (!new_str)
		return (NULL);
	index = 2;
	while (av[index])
	{
		tmp = ft_strjoin(new_str, " ");
		free(new_str);
		if (!tmp)
			return (NULL);
		new_str = tmp;
		tmp = ft_strjoin(new_str, av[index++]);
		free(new_str);
		if (!tmp)
			return (NULL);
		new_str = tmp;
	}
	return (new_str);
}

static t_list	*setup_stack(char **av, t_list *stack_a)
{
	int		result;
	int		index;
	bool	flag;

	flag = false;
	index = 0;
	result = 0;
	if (av[2])
	{
		av[1] = join_av1(av);
		if (!av[1])
			return (NULL);
		flag = true;
	}
	while (av[1][index])
	{
		result = atoi_parsing(av, &index, stack_a);
		stack_a = create_stack_a(stack_a, result);
	}
	if (check_double(stack_a))
		return (display_error(DOUBLE_ERROR, stack_a, av), NULL);
	if (flag == true)
		free(av[1]);
	return (stack_a);
}

void	start_push_swap(char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_empty_arg(av))
		display_error("Empty argument", stack_a, NULL);
	stack_a = setup_stack(av, stack_a);
	if (!stack_a)
		return ;
	if (ft_lstsize(stack_a) == 2)
	{
		if (stack_a->content > stack_a->next->content)
			swap_sa_sb(&stack_a, 'a');
	}
	else if (ft_lstsize(stack_a) == 3)
		algo_3_numbers(&stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
		init_algo_4_5(&stack_a, &stack_b);
	else if (!is_sort(&stack_a))
		init_final_algo(&stack_a, &stack_b);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}
