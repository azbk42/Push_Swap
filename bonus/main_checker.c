/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:08:51 by azbk              #+#    #+#             */
/*   Updated: 2024/01/19 13:28:53 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_exit(t_list *stack_a, t_list *stack_b, char *av)
{
	if (av)
		free(av);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("KO\n", 1);
	exit(EXIT_FAILURE);
}

void	exec_bonus(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		shift_ra_rb(stack_a, '0');
	else if (!ft_strncmp(line, "rb\n", 3))
		shift_ra_rb(stack_b, '0');
	else if (!ft_strncmp(line, "rr\n", 3))
		shift_rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		shift_rra_rrb(stack_a, '0');
	else if (!ft_strncmp(line, "rrb\n", 4))
		shift_rra_rrb(stack_b, '0');
	else if (!ft_strncmp(line, "rrr\n", 4))
		shift_rrr(stack_a, stack_b);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap_sa_sb(stack_a, '0');
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_sa_sb(stack_b, '0');
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_b(stack_a, stack_b);
	else
		free_exit(*stack_a, *stack_b, line);
}

void	init_bonus(t_list *stack_a, t_list *stack_b)
{
	char	*line;

	while (true)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		exec_bonus(&stack_a, &stack_b, line);
		free(line);
	}
	if (is_sort(&stack_a) && ft_lstsize(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		start_push_swap(av);
	else
		display_error("\nError: no argument\n", NULL, NULL);
	return (0);
}
