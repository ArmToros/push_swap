/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:41:46 by armtoros          #+#    #+#             */
/*   Updated: 2025/07/10 21:41:47 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->next->number < stack->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sorting(t_stack **a, t_stack **b, int i)
{
	int	len;
	int	*arr;

	len = list_size(a);
	arr = list_to_arr(a, len);
	arr_sort(arr, len);
	init_index(a, arr, len);
	free(arr);
	if (len == 2)
		sort_two(a, i);
	else if (len == 3)
		sort_three(a, i);
	else if (len == 4)
		sort_four(a, b, i);
	else if (len == 5)
		sort_five(a, b, i);
	else
		butterfly(a, b, get_n(len), i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	init_args(argv, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	sorting(&a, &b, 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
