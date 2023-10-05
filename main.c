#include <stdio.h>
#include "push_swap.h"


void start_push_swap(char **av, t_list *stack_a, t_list *stack_b)
{
   int index;
   int result;

   result = 0;
   index = 0;
   if (!av[1][0])
      display_error();
   while (av[1][index])
   {
      result = atoi_parsing(av[1], &index);
      if (check_double(stack_a, result))
         display_error();
      stack_a = create_stack_a(stack_a, result);
   }
   stack_b = create_stack_a(stack_b, 50);
   stack_b = create_stack_a(stack_b, 60);
   stack_b = create_stack_a(stack_b, 70);
   stack_b = create_stack_a(stack_b, 80);
   // stack_a est cree maintenant on doit creer les algo.
   print_stacks(stack_a, stack_b);

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
