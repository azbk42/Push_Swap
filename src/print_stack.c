#include "../includes/push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d ", current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("_  ");
		ft_printf("    ");
		if (current_b)
		{
			ft_printf("%d", current_b->content);
			current_b = current_b->next;
		}
		else
			ft_printf("_");
		ft_printf("\n");
	}
	ft_printf("A      B\n");
	ft_printf("\n");
}
