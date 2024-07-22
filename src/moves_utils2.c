/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:11:27 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 17:09:29 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	push_to_stack(t_stack_node **target, t_stack_node **source)
{
	t_stack_node	*temp;

	temp = *source;
	(*source) = (*source)->next;
	(*source)->prev = NULL;
	temp->prev = NULL;
	if (!*target)
	{
		*target = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *target;
		temp->next->prev = temp;
		*target = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_to_stack(*a, *b);
	ft_printf("pa");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_to_stack(b, a);
	ft_printf("pb");
}
