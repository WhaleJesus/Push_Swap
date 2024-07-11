/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:09:00 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/11 14:40:42 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	sa(t_stack_node **a, bool check)
{
	swap_top(*a);
	if (!check)
		printf("sa");
}

void	sb(t_stack_node **b, bool check)
{
	swap_top(*b);
	if (!check)
		printf("sb");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a, true);
	sb(b, true);
	printf("ss");
}

void	ra(t_stack_node **a, bool check)
{
	push_to_bottom(*a);
	if (!check)
		printf("ra");
}

void	rb(t_stack_node **b, bool check)
{
	push_to_bottom(*b);
	if (!check)
		printf("rb");
}
