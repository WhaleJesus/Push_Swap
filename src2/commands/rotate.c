/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:10:08 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/29 15:03:26 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	(*stack) = (*stack)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_stack(t_stack_node **stack, char *target, bool msg)
{
	rotate(stack);
	if (!msg)
		ft_printf("%s\n", target);
}

void	rr(t_stack_node **a, t_stack_node **b, bool msg)
{
	rotate(a);
	rotate(b);
	if (!msg)
		ft_printf("rr\n");
}
