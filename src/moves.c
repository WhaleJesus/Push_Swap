/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:09:00 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 16:05:38 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	sa(t_stack_node **a, bool check)
{
	swap_top(*a);
	if (!check)
		ft_printf("sa");
}

void	sb(t_stack_node **b, bool check)
{
	swap_top(*b);
	if (!check)
		ft_printf("sb");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a, true);
	sb(b, true);
	ft_printf("ss");
}

void	ra(t_stack_node **a, bool check)
{
	push_to_bottom(*a);
	if (!check)
		ft_printf("ra");
}

void	rb(t_stack_node **b, bool check)
{
	push_to_bottom(*b);
	if (!check)
		ft_printf("rb");
}
