/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:45:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/09/03 14:41:57 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = get_min_max(*a, 1);
	if (biggest == *a)
		rotate_stack(a, "ra", false);
	else if ((*a)->next == biggest)
		rev_rotate_stack(a, "rra", false);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_stack(a, "sa", false);
}
