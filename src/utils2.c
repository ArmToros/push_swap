#include "push_swap.h"

int	list_size(t_stack **a)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	small_value(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*start;

	start = *a;
	tmp = (*a)->next;
	while (start != NULL && tmp != NULL)
	{
		if (start->number < tmp->number)
			tmp = tmp->next;
		else
		{
			start = tmp;
			tmp = tmp->next;
		}
	}
	return (start->number);
}

void	if_else(t_stack **b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, size);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b, size);
			pos--;
		}
	}
}

void	parse_split(char **split, t_stack **a)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]))
		{
			free_split(split);
			print_error(a);
		}
		if (!is_double(*a, ft_atoi(split[i])))
		{
			free_split(split);
			print_error(a);
		}
		if (!ft_atolli(split[i], 1))
		{
			free_split(split);
			print_error(a);
		}
		push_back(a, ft_atoi(split[i]));
		i++;
	}
}

int	is_array_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
