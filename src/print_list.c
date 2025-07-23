/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:26 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:37:28 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	print_rank(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	while (node)
	{
		ft_printf("n: %i, rank: %i\n", node->num, node->rank);
		node = node->next;
	}
}

void	print_stack(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	ft_printf("stack:\n");
	while (node)
	{
		ft_printf("%i\n", node->num);
		node = node->next;
	}
}

void	print_list_all(t_stack *stack, char type)
{
	if (!stack)
		return ;
	ft_printf("---------\n%c\n", type);
	while (stack)
	{
		ft_printf("------------------\n");
		ft_printf("num: %i\n", stack->num);
		ft_printf("rank: %i\n", stack->rank);
		if (stack->target)
			ft_printf("tgt: %i\n", stack->target->num);
		ft_printf("cost: %i\n", stack->cost);
		ft_printf("median: %i\n", stack->median);
		stack = stack->next;
	}
}
