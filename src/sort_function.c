#include "../includes/push_swap.h"

void swap_sa_sb(t_list **stack, char c)
{
    if (*stack == NULL)
        return;
    int tmp;
    t_list *current;

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

void swap_ss(t_list **stack_a, t_list **stack_b)
{
    swap_sa_sb(stack_a, '0');
    swap_sa_sb(stack_b, 's');
}

void push_b(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a == NULL)
        return;
    t_list *current;
    t_list *new;
    int tmp;

    current = *stack_a;
    tmp = current->content;
    new = ft_lstnew(tmp);
    ft_lstadd_front(stack_b, new);
    *stack_a = current->next;
    free(current);
    ft_printf("pb\n");
}

void push_a(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b == NULL)
        return;
    t_list *current;
    t_list *new;
    int tmp;

    current = *stack_b;
    tmp = current->content;
    new = ft_lstnew(tmp);
    ft_lstadd_front(stack_a, new);
    *stack_b = current->next;
    free(current);
    ft_printf("pa\n");
}

