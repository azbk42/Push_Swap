#include <stdio.h>
#include "push_swap.h"


void start_push_swap(char **av, t_list *stack_a, t_list *stack_b)
{
   int index;
   int result;

   result = 0;
   index = 0;
   while (av[1][index])
   {
      result = atoi_parsing(av[1], &index);
      stack_a = create_stack_a(stack_a, result);
   }
   if (stack_b)
      print_stack(&stack_b);
   print_stack(&stack_a);
}

int main(int ac, char **av) 
{
   t_list *stack_a;
   t_list *stack_b;

   stack_a = NULL;
   stack_b = NULL;
   if (ac == 2)
      start_push_swap(av, stack_a, stack_b);
   else
      display_error();
}

