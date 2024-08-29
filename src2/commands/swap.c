/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:17:17 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/29 15:04:32 by sklaps           ###   ########.fr       */
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

void	swap_stack(t_stack_node **stack, char *target, bool msg)
{
	swap(target);
	if (!msg)
		ft_printf("%s\n", target);
}

void	ss(t_stack_node **a, t_stack_node **b, bool msg)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
