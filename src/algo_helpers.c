#include "../includes/ps.h"

int	find_min_index(t_stack *head)
{
	int		i;
	t_stack	*stack;
	t_stack	*min;

	if (!head)
		return (0);
	stack = head;
	min = get_min(stack);
	i = 0;
	while (stack)
	{
		if (stack->num == min->num)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	push_smallest_to_b(t_data *data)
{
	int		min;
	t_stack	*min_s;

	min = find_min_index(data->a);
	min_s = get_min(data->a);
	while (data->a->num != min_s->num)
	{
		if (min > stacklen(&(data->a)) / 2)
			reverse_rotate(data, &(data->a), "rra");
		else
			rotate(data, &(data->a), "ra");
	}
	push(data, &(data->a), &(data->b), "pb");
}

void	sort_five(t_data *data)
{
	push_smallest_to_b(data);
	push_smallest_to_b(data);
	sort_three(data);
	if (data->b->num < data->b->next->num)
		rotate(data, &(data->b), "rb");
	push(data, &(data->b), &(data->a), "pa");
	push(data, &(data->b), &(data->a), "pa");
}
