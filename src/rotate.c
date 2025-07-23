/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:13:10 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 23:13:11 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	rotate(t_data *data, t_stack **stack, char *type)
{
	t_stack	*top;
	t_stack	*last;

	if (!stack || !(*stack))
		return ;
	if (stacklen(stack) < 2)
		return ;
	top = *stack;
	last = get_last(stack);
	*stack = top->next;
	top->next = NULL;
	top->prev = last;
	last->next = top;
	(*stack)->prev = NULL;
	if (ft_strlen(type) > 0)
		opmsg(data, type);
}

void	rotate_both(t_data *data)
{
	rotate(data, &(data->a), "");
	rotate(data, &(data->b), "");
	opmsg(data, "rr");
	data->rr++;
}

void	reverse_rotate(t_data *data, t_stack **stack, char *type)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = get_last(stack);
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (ft_strlen(type) > 0)
		opmsg(data, type);
}

void	rrr(t_data *data)
{
	reverse_rotate(data, &(data->a), "");
	reverse_rotate(data, &(data->b), "");
	opmsg(data, "rrr");
	data->rrr++;
}
