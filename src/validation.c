#include "push_swap.h"

int	is_double(t_stack *stack, int number)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->number == number)
			count++;
		stack = stack->next;
	}
	if (count >= 1)
		return (0);
	return (1);
}

int	is_empty(char *value)  
{
	int	i;
	int	flag;

	if (*value == '\0')
		return (0);
	i = 0;
	flag = 0;
	while (value[i])
	{
		if (value[i] != ' ')
			flag = 1;
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

int	is_number(char *value)
{
	int	i;

	if (!value || value[0] == '\0')
		return (0);
	i = 0;
	if (value[i] == '-' || value[i] == '+')
		i++;
	if (!value[i])
		return (0);
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	return (1);
}
