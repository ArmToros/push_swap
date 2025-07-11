/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:42:27 by armtoros          #+#    #+#             */
/*   Updated: 2025/07/10 21:43:33 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack **stack, int *arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->number)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	*list_to_arr(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = *stack;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size && tmp)
	{
		arr[i] = tmp->number;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	arr_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	mini(t_stack **a)
{
	t_stack	*tmp;
	int		data;
	int		min_pos;
	int		index;

	if (*a == NULL)
		return (-1);
	tmp = *a;
	data = tmp->number;
	min_pos = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->number < data)
		{
			data = tmp->number;
			min_pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	if (min_pos <= list_size(a) / 2)
		return (min_pos);
	else
		return (min_pos - list_size(a));
}

void	min_pos_rev(t_stack **list, int min_pos, int i)
{
	int	size;

	size = list_size(list);
	if (min_pos == 0)
		return ;
	if (min_pos > 0 && min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(list, i);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < 0)
		{
			rra(list, i);
			min_pos++;
		}
	}
}
