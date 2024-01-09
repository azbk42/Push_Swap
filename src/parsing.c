#include "../includes/push_swap.h"

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
        display_error(NO_DIGIT_ERROR);
    while (ft_isdigit(str[*index]))
        result = (result * 10) + (str[(*index)++] - '0');
    while (str[*index] == ' ')
        (*index) ++;
    result = result * divid;
    if (result > INT_MAX || result < INT_MIN)
        display_error(INT_MAX_MIN_ERROR);
    return (result * divid);
}   

