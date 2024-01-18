#include "../../includes/push_swap.h"

void	swap_sa_sb(t_list **stack, char c)
{
	int		tmp;
	t_list	*current;

	if (*stack == NULL)
		return ;
	current = *stack;
	tmp = current->content;
	current->content = current->next->content;
	current->next->content = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else if (c == 's')
		ft_printf("ss\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_sa_sb(stack_a, '0');
	swap_sa_sb(stack_b, 's');
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (*stack_b == NULL)
		return ;
	current = *stack_b;
	*stack_b = current->next;
	current->next = *stack_a;
	*stack_a = current;
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (*stack_a == NULL)
		return ;
	current = *stack_a;
	*stack_a = current->next;
	current->next = *stack_b;
	*stack_b = current;
	ft_printf("pb\n");
}
