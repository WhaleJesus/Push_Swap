/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:12:45 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 23:12:46 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate_min_top(t_data *data, t_stack *stack)
{
	t_stack	*min;

	min = get_min(stack);
	while (data->a->num != min->num)
	{
		if (min->median)
			reverse_rotate(data, &data->a, "rra");
		else
			rotate(data, &data->a, "ra");
	}
}

void	get_median(t_stack *s, t_stack *node)
{
	int		i;
	int		len;
	t_stack	*stack;

	stack = s;
	len = stacklen(&stack);
	i = 1;
	while (stack)
	{
		if (stack->num == node->num)
			break ;
		i++;
		stack = stack->next;
	}
	if (i > len / 2)
		node->median = 1;
	else
		node->median = 0;
}

t_stack	*get_cheapest(t_stack *stack)
{
	int		cost;
	t_stack	*node;

	cost = INT_MAX;
	node = stack;
	while (node)
	{
		if (node->cost < cost)
			cost = node->cost;
		node = node->next;
	}
	node = stack;
	while (node)
	{
		if (node->cost == cost)
			break ;
		node = node->next;
	}
	return (node);
}
