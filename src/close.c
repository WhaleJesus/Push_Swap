/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:27:50 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 15:33:02 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while ((*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}
