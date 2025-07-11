/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:42:02 by armtoros          #+#    #+#             */
/*   Updated: 2025/07/10 21:42:03 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int i)
{
	int	tmp;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	if (i)
		ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (i)
		ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	if (i)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = NULL;
	last = *b;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	if (last)
		last->next = NULL;
	first -> next = NULL;
	last->next = *b;
	*b = last;
	if (i)
		ft_putstr_fd("rrb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int i)
{
	ra(a, i);
	rb(b, i);
	if (i)
		ft_putstr_fd("rr\n", 1);
}
