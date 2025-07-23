/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:38:19 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:38:26 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	opmsg(t_data *data, char *msg)
{
	if (!ft_strncmp(msg, "pa", ft_strlen("pa") + 1))
		data->pa++;
	else if (!ft_strncmp(msg, "pb", ft_strlen("pb") + 1))
		data->pb++;
	else if (!ft_strncmp(msg, "ra", ft_strlen("ra") + 1))
		data->ra++;
	else if (!ft_strncmp(msg, "rb", ft_strlen("rb") + 1))
		data->rb++;
	else if (!ft_strncmp(msg, "rra", ft_strlen("rra") + 1))
		data->rra++;
	else if (!ft_strncmp(msg, "rrb", ft_strlen("rrb") + 1))
		data->rrb++;
	data->op_count++;
	ft_printf("%s\n", msg);
}

void	swap_a(t_data *data, t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	if (print)
	{
		data->sa++;
		opmsg(data, "sa");
	}
}

void	swap_b(t_data *data, t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	if (print)
	{
		data->sb++;
		opmsg(data, "sb");
	}
}

void	swap_both(t_data *data)
{
	swap_a(data, &(data->a), 0);
	swap_b(data, &(data->b), 0);
	opmsg(data, "ss");
	data->ss++;
}
