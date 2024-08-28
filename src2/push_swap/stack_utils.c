/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:43:41 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/28 11:14:42 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*get_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->next)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*get_min_max(t_stack_node *stack, int check)
{
	long			min_max;
	t_stack_node	*min_max_node;

	if (!stack)
		return (NULL);
	min_max = LONG_MAX;
	if (check == 1)
		min_max = LONG_MIN;
	while (stack)
	{
		if ((stack->nbr < min_max && check == 0) || 
			(stack->nbr > min_max && check == 1))
		{
			min_max = stack->nbr;
			min_max_node = stack;
		}
		stack = stack->next;
	}
	return (min_max_node);
}

t_stack_node *get_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
