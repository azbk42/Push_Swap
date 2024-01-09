#include "../includes/push_swap.h"

void shift_rra_rrb(t_list **stack, char c)
{
    t_list *current;
    int tmp;

    current = *stack;
    while (current->next->next)
        current = current->next;
    tmp = current->next->content;
    free(current->next);
    current->next = NULL;
    *stack = create_stack_a(*stack, tmp);
    current = *stack;
    if (c == 'a')
        ft_printf("rra\n");
    if (c == 'b')
        ft_printf("rrb\n");
    if (c == 'r')
        ft_printf("rrr\n"); 
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
