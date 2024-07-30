/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:18:12 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/30 08:24:14 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool msg)
{
	push(a, b);
	if (!msg)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool msg)
{
	push(b, a);
	if (!msg)
		ft_printf("pb\n");
}
