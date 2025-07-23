/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:12:39 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 23:12:40 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

t_stack	*get_min(t_stack *head)
{
	t_stack	*i;
	t_stack	*stack;

	if (!head)
		return (0);
	stack = head;
	i = stack;
	while (stack)
	{
		if (stack->num < i->num)
			i = stack;
		stack = stack->next;
	}
	return (i);
}

t_stack	*get_max(t_stack *head)
{
	t_stack	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head)
	{
		if (head->num > max->num)
			max = head;
		head = head->next;
	}
	return (max);
}

int	get_index(t_stack *stack, t_stack *node)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == node)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_cost(t_stack *stack1, t_stack *stack2, int i1, int i2)
{
	int	len1;
	int	len2;
	int	both;

	both = 1;
	len1 = stacklen(&stack1);
	len2 = stacklen(&stack2);
	if ((i1 > len1 / 2 && i2 > len2 / 2)
		|| (i1 < len1 / 2 && i1 < len2 / 2))
		both = 2;
	if (i1 > len1 / 2)
		i1 = len1 - i1;
	if (i2 > len2 / 2)
		i2 = len2 - i2;
	if (both == 2)
	{
		if (i2 > i1)
			return (i2 + 1);
		return (i1 + 1);
	}
	return (i2 + i1);
}
