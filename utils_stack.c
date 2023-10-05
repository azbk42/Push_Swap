#include "push_swap.h"

t_list *create_stack_a(t_list *stack_a, int number)
{
   t_list *new;

   new = ft_lstnew(number);
   if (!new)
      return (NULL);
   ft_lstadd_front(&stack_a, new);
   return (stack_a);
}

void print_stacks(t_list *stack_a, t_list *stack_b) 
{
   t_list *current_a;
   t_list *current_b;

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
}