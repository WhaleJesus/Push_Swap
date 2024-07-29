/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:17:17 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/29 20:04:02 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

static void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev-prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, bool msg)
{
	swap(a);
	if (!msg)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool msg)
{
	swap(b);
	if (!msg)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool msg)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
