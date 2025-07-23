/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:16 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:37:18 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	circle_sort(t_stack *stack)
{
	int		drops;
	t_stack	*curr;

	drops = 0;
	curr = stack;
	if (!stack)
		return (1);
	while (curr->next)
	{
		if (curr->num > curr->next->num)
			drops++;
		curr = curr->next;
	}
	if (curr->num > stack->num)
		drops++;
	return (drops <= 1);
}

int	is_sorted(t_stack **s)
{
	t_stack	*stack;

	stack = *s;
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->op_count = 0;
	data->pa = 0;
	data->pb = 0;
	data->sa = 0;
	data->sb = 0;
	data->ss = 0;
	data->ra = 0;
	data->rb = 0;
	data->rr = 0;
	data->rra = 0;
	data->rrb = 0;
	data->rrr = 0;
	data->debug = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (1);
	init_data(&data);
	av = split_args(av);
	check_input(av);
	init_stack(&data.a, av);
	if (!is_sorted(&data.a))
		algo(&data);
	exit_program(&data, av);
}
