#include "../includes/push_swap.h"

int	atoi_parsing(char **str, int *index, t_list *stack_a)
{
	long	result;
	int		divid;

	divid = 1;
	result = 0;
	if (*index > 0 && str[1][*index] != ' ')
		display_error("Error", stack_a, str);
	while (str[1][*index] == ' ')
		(*index)++;
	if (str[1][*index] == '-' || str[1][*index] == '+')
		if (str[1][(*index)++] == '-')
			divid = -1;
	if (!ft_isdigit(str[1][*index]))
		display_error(NO_DIGIT_ERROR, stack_a, str);
	while (ft_isdigit(str[1][*index]))
	{
		result = (result * 10) + (str[1][(*index)++] - '0');
		if ((result * divid) > INT_MAX || (result * divid) < INT_MIN)
			display_error(INT_MAX_MIN_ERROR, stack_a, str);
	}
	result = result * divid;
	return (result);
}
