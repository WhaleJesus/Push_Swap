/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:30:57 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:31:00 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	sort_two(t_data *data)
{
	if (is_sorted(&(data->a)))
		return ;
	swap_a(data, &(data->a), 1);
}

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a->num;
	second = data->a->next->num;
	third = data->a->next->next->num;
	if (first > second && second < third && first < third)
		swap_a(data, &(data->a), 1);
	else if (first > second && second > third)
	{
		swap_a(data, &(data->a), 1);
		reverse_rotate(data, &(data->a), "rra");
	}
	else if (first > second && second < third && first > third)
		rotate(data, &(data->a), "ra");
	else if (first < second && second > third && first < third)
	{
		swap_a(data, &(data->a), 1);
		rotate(data, &(data->a), "ra");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(data, &(data->a), "rra");
}

void	rank_stack(t_data *data)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	int		rank;

	ptr1 = data->a;
	while (ptr1)
	{
		rank = 0;
		ptr2 = data->a;
		while (ptr2)
		{
			if (ptr2->num < ptr1->num)
				rank++;
			ptr2 = ptr2->next;
		}
		ptr1->rank = rank;
		ptr1 = ptr1->next;
	}
}

void	sort_four(t_data *data)
{
	int min_index;

	min_index = find_min_index(data->a);
	if (min_index == 1)
		rotate(data, &(data->a), "ra");
	else if (min_index == 2)
	{
		rotate(data, &(data->a), "ra");
		rotate(data, &(data->a), "ra");
	}
	else if (min_index == 3)
		reverse_rotate(data, &(data->a), "rra");
	push(data, &(data->a), &(data->b), "pb");
	sort_three(data);
	push(data, &(data->b), &(data->a), "pa");
}

void	algo(t_data *data)
{
	int	len;

	if (!data || !data->a)
		return ;
	rank_stack(data);
	len = stacklen(&(data->a));
	if (len == 2)
		sort_two(data);
	else if (len == 3)
		sort_three(data);
	else if (len == 4)
		sort_four(data);
	else if (len == 5)
		sort_five(data);
	else
		turk_algo(data);
}
