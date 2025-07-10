#include "push_swap.h"

void	sort_two(t_stack **a, int i)
{
	t_stack	*tmp;

	tmp = *a;
	if (is_sorted(*a))
		return ;
	if (tmp->number > tmp->next->number)
		sa(a, i);
}

void	sort_three(t_stack **list, int i)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if (a > b && a < c)
		sa(list, i);
	else if (a < b && a > c)
		rra(list, i);
	else if (a > b && a > c && b < c)
		ra(list, i);
	else if (a > b && a > c && b > c)
	{
		sa(list, i);
		rra(list, i);
	}
	else if (a < b && a < c && b > c)
	{
		sa(list, i);
		ra(list, i);
	}
}

void	sort_four(t_stack **a, t_stack **b, int i)
{
	int		min_pos;

	if (is_sorted(*a))
		return ;
	min_pos = mini(a);
	min_pos_rev(a, min_pos, i);
	pb(a, b, i);
	sort_three(a, i);
	pa(a, b, i);
}

void	sort_five(t_stack **a, t_stack **b, int i)
{
	int	count;
	int	min_pos;

	count = 2;
	if (is_sorted(*a))
		return ;
	while (count > 0)
	{
		min_pos = mini(a);
		min_pos_rev(a, min_pos, i);
		pb(a, b, i);
		count--;
	}
	sort_three(a, i);
	pa(a, b, i);
	pa(a, b, i);
}
