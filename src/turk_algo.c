/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:52 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:37:53 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

static void	get_target(t_data *data, t_stack *a, t_stack *b)
{
	t_stack	*sb;
	t_stack	*best;

	while (a)
	{
		sb = b;
		best = NULL;
		while (sb)
		{
			if (sb->num < a->num && (!best || sb->num > best->num))
				best = sb;
			sb = sb->next;
		}
		if (!best)
			best = get_max(b);
		a->target = best;
		get_median(data->a, a);
		get_median(data->b, best);
		a->cost = get_cost(data->a, data->b,
				get_index(data->a, a),
				get_index(data->b, best));
		a = a->next;
	}
}

static void	get_target_b(t_data *data, t_stack *a, t_stack *b)
{
	t_stack	*ta;
	t_stack	*best;

	while (b)
	{
		ta = a;
		best = NULL;
		while (ta)
		{
			if (ta->num > b->num && (!best || ta->num < best->num))
				best = ta;
			ta = ta->next;
		}
		if (!best)
			best = get_min(a);
		b->target = best;
		get_median(data->a, best);
		get_median(data->b, b);
		b->cost = get_cost(data->a, data->b,
				get_index(data->a, best),
				get_index(data->b, b));
		b = b->next;
	}
}

static void	push_to_a(t_data *data, t_stack *cheapest)
{
	if (!cheapest || !cheapest->target)
		return ;
	while (data->b->num != cheapest->num
		|| data->a->num != cheapest->target->num)
	{
		if (cheapest->median && cheapest->target->median
			&& data->b->num != cheapest->num
			&& data->a->num != cheapest->target->num)
			rrr(data);
		else if (!(cheapest->median) && !(cheapest->target->median)
			&& data->b->num != cheapest->num
			&& data->a->num != cheapest->target->num)
			rotate_both(data);
		else
			push_to_a_extended(data, cheapest);
	}
	push(data, &data->b, &data->a, "pa");
}

static void	push_to_b(t_data *data, t_stack *cheapest)
{
	if (!cheapest || !cheapest->target)
		return ;
	while (data->a->num != cheapest->num
		|| data->b->num != cheapest->target->num)
	{
		if (cheapest->median && cheapest->target->median
			&& data->a->num != cheapest->num
			&& data->b->num != cheapest->target->num)
			rrr(data);
		else if (!(cheapest->median) && !(cheapest->target->median)
			&& data->a->num != cheapest->num
			&& data->b->num != cheapest->target->num)
			rotate_both(data);
		else
			push_to_b_extended(data, cheapest);
	}
	push(data, &data->a, &data->b, "pb");
}

void	turk_algo(t_data *data)
{
	if (stacklen(&data->a) > 3)
		push(data, &data->a, &data->b, "pb");
	if (stacklen(&data->a) > 3)
		push(data, &data->a, &data->b, "pb");
	while (!is_sorted(&data->a) && !circle_sort(data->a))
	{
		if (stacklen(&data->a) == 3)
			sort_three(data);
		else
		{
			get_target(data, data->a, data->b);
			push_to_b(data, get_cheapest(data->a));
		}
	}
	while (stacklen(&data->b) > 0)
	{
		get_target_b(data, data->a, data->b);
		push_to_a(data, get_cheapest(data->b));
	}
	rotate_min_top(data, data->a);
}
