/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:54:47 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/30 16:41:01 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rev_rotate_stack(t_stack_node **stack, char *target, bool msg)
{
	rev_rotate(stack);
	if (!msg)
		ft_printf("%s\n", target);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool msg)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!msg)
		ft_printf("rrr\n");
}
