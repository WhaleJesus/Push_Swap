/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_push_more_than_25_lines.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:12:30 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 23:12:33 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	push_to_a_extended(t_data *data, t_stack *cheapest)
{
	if (data->b->num != cheapest->num)
	{
		if (cheapest->median)
			reverse_rotate(data, &data->b, "rrb");
		else
			rotate(data, &data->b, "rb");
	}
	if (data->a->num != cheapest->target->num)
	{
		if (cheapest->target->median)
			reverse_rotate(data, &data->a, "rra");
		else
			rotate(data, &data->a, "ra");
	}
}

void	push_to_b_extended(t_data *data, t_stack *cheapest)
{
	if (data->a->num != cheapest->num)
	{
		if (cheapest->median)
			reverse_rotate(data, &data->a, "rra");
		else
			rotate(data, &data->a, "ra");
	}
	if (data->b->num != cheapest->target->num)
	{
		if (cheapest->target->median)
			reverse_rotate(data, &data->b, "rrb");
		else
			rotate(data, &data->b, "rb");
	}
}
