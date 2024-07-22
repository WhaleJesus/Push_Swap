/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:31:20 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 16:06:12 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a, true);
	rb(b, true);
	ft_printf("rr");
}

void	rra(t_stack_node **a, bool check)
{
	push_to_top(*a);
	if (!check)
		ft_printf("rra");
}

void	rrb(t_stack_node **b, bool check)
{
	push_to_top(*b);
	if (!check)
		ft_printf("rrb");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a, true);
	rrb(b, true);
	ft_printf("rrr");
}
