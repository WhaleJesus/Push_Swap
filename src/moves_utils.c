/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:40:10 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 16:07:56 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

t_stack_node	*stack_getn(t_stack_node *stack, int nbr)
{
	int	i;

	i = 1;
	while (i < nbr)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

t_stack_node	*stack_getlast(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	swap_top(t_stack_node *stack)
{
	t_stack_node	*temp_node;
	int				len;

	len = stack_len(stack);
	if (len < 2)
		return ;
	temp_node = stack_getn(stack, 3);
	stack->prev = stack->next;
	stack->next = temp_node;
	temp_node = stack;
	stack = stack->prev;
	stack->next = temp_node;
	stack->prev = NULL;
}

void	push_to_bottom(t_stack_node *stack)
{
	stack->prev = stack_getlast(stack);
	stack->next->prev = NULL;
	stack->next = NULL;
	while (stack->prev)
		stack = stack->prev;
}

void	push_to_top(t_stack_node *stack)
{
	t_stack_node	*temp_node;

	while (stack->next)
		stack = stack->next;
	temp_node = stack;
	stack = stack->prev;
	stack->next = NULL;
	while (stack->prev)
		stack = stack->prev;
	temp_node->next = stack;
	stack->prev = temp_node;
	stack = stack->prev;
	stack->prev = NULL;
}
