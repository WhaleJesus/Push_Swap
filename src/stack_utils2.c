/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:39:57 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 16:44:19 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			break;
		stack = stack->next;
	}
	return (stack);
}
