#include "../includes/push_swap.h"

int atoi_parsing(char *str, int *index, t_list *stack_a)
{
    long result;
    int divid;

    divid = 1; 
    result = 0;
    if (*index > 0 && str[*index] != ' ')
        display_error("LOOOOOOOOOOOL", stack_a);
    while (str[*index] == ' ')
        (*index) ++;
    if (str[*index] == '-' || str[*index] == '+')
        if (str[(*index)++] == '-')
            divid = -1;
    if (!ft_isdigit(str[*index]))
        display_error(NO_DIGIT_ERROR, stack_a);    
    while (ft_isdigit(str[*index]))
    {
        result = (result * 10) + (str[(*index)++] - '0');
        if ((result * divid) > INT_MAX || (result * divid) < INT_MIN)
            display_error(INT_MAX_MIN_ERROR, stack_a);
    }
    result = result * divid;
    return (result);
}   

