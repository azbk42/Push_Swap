#include "../../includes/push_swap.h"

void shift_rra_rrb(t_list **stack, char c)
{
    if (*stack == NULL)
        return;
    t_list *current;
    t_list *tmp_last;

    current = *stack;
    while (current->next->next)
        current = current->next;
    tmp_last = current->next;
    tmp_last->next = *stack;
    current->next = NULL;
    *stack = tmp_last;
    if (c == 'd')
        ft_printf("rrr\n");
    else
        ft_printf("rr%c\n", c);
}
void shift_rrr(t_list **stack_a, t_list **stack_b)
{
    shift_rra_rrb(stack_a, 'r');
    shift_rra_rrb(stack_b, 'd');
}
void shift_rr(t_list **stack_a, t_list **stack_b)
{
    shift_ra_rb(stack_a, 's');
    shift_ra_rb(stack_b, 'd');
}
void shift_ra_rb(t_list **stack, char c)
{
    if (*stack == NULL)
        return;
    t_list *current;
    t_list *new;
    int tmp;

    current = *stack;
    tmp = current->content;
    new = ft_lstnew(tmp);
    *stack = current->next;
    ft_lstadd_back(stack, new);
    if (c == 'a')
        ft_printf("ra\n");
    else if (c == 'b')
        ft_printf("rb\n");
    else if (c == 's')
        ft_printf("rr\n");
}
