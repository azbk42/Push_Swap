#include "push_swap.h"

t_list *create_stack_a(t_list *stack_a, int number)
{
   t_list *new;

   new = ft_lstnew(number);
   if (!new)
      return (NULL);
   ft_lstadd_back(&stack_a, new);
   return (stack_a);
}

void print_stack(t_list **stack)
{
   t_list *current;

   current = *stack;

   while (current)
   {
      ft_printf("%d\n", current->content);
      current = current->next;
   }
   ft_printf("_ _\na b\n");
}
