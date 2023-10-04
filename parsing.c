#include "push_swap.h"


void display_error()
{
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}

int atoi_parsing(char *str, int *index)
{
    long result;
    int divid;

    divid = 1; 
    result = 0;
    while (str[*index] == ' ')
        (*index) ++;
    if (str[*index] == '-' || str[*index] == '+')
    {
        if (str[*index] == '-')
            divid = -1;
        (*index) ++;
    }
    if (!ft_isdigit(str[*index]))
        display_error();
    while (ft_isdigit(str[*index]))
    {
        result = (result * 10) + (str[*index] - '0');
        (*index)++;
    }
    while (str[*index] == ' ')
        (*index) ++;
    if (result > INT_MAX || result < INT_MIN)
        display_error();
    return (result * divid);
}   
bool check_double(t_list *stack_a, int nb)
{
    t_list *current;

    current = stack_a;

    while (current)
    {
        if (current->content == nb)
            return true;
        else
            current = current->next;
    }
    return false;
}
