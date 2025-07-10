#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	free_split(char **split);
bool	ft_atolli(char *arg, int sign);
void	free_stack(t_stack **stack);
void	push_back(t_stack **stack, int number);
int		is_double(t_stack *stack, int number);
int		is_empty(char *argument);
int		is_number(char *argument);
void	init_args(char **argv, t_stack **a);
void	parse_split(char **split, t_stack **a);
int		is_sorted(t_stack *a);
void	sa(t_stack **a, int i);
void	pa(t_stack **a, t_stack **b, int i);
void	ra(t_stack **a, int i);
void	rra(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	pb(t_stack **a, t_stack **b, int i);
void	rb(t_stack **b, int i);
void	rrb(t_stack **b, int i);
void	ss(t_stack **a, t_stack **b, int i);
void	rr(t_stack **a, t_stack **b, int i);
void	rrr(t_stack **a, t_stack **b, int i);
int		*list_to_arr(t_stack **stack, int size);
int		mini(t_stack **a);
int		list_size(t_stack **a);
void	arr_sort(int *arr, int size);
void	init_index(t_stack **stack, int *arr, int size);
void	min_pos_rev(t_stack **list, int min_pos, int i);
void	print_error(t_stack **stack);
void	sort_two(t_stack **a, int i);
void	sort_three(t_stack **list, int i);
void	sort_four(t_stack **a, t_stack **b, int i);
void	sort_five(t_stack **a, t_stack **b, int i);
size_t	get_n(size_t lstsize);
void	if_else(t_stack **b, int pos, int size);
void	butterfly(t_stack **a, t_stack **b, int n, int i);

#endif