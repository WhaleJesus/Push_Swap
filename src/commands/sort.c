/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:15:54 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/30 19:44:04 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest, char *type)
{
	if (!ft_strncmp(type, "r", ft_strlen(type)))
	{
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b, false);
	}
	else if (!ft_strncmp(type, "rev", ft_strlen(type)))
	{
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	move_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest, "r");
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rotate_both(a, b, cheapest, "rev");
	push_prep(a, cheapest, 'a');
	push_prep(b, cheapest->target, 'b');
	papb(a, b, 'b', false);
}

static void	move_b_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target, 'a');
	papb(a, b, 'b', false);
}

static void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != get_min_max(*a, 0)->nbr)
	{
		if (get_min_max(*a, 0)->above_median)
			rotate_stack(a, "a", false);
		else
			rev_rotate_stack(a, "rra", false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		papb(a, b, 'b', false);
	if (len_a-- > 3 && !stack_sorted(*a))
		papb(a, b, 'b', false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	min_top(a);
}
