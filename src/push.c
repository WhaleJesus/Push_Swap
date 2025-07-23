/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:36 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:37:46 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	push(t_data *data, t_stack **src, t_stack **dest, char *type)
{
	t_stack	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		tmp->next = NULL;
		*dest = tmp;
	}
	else
	{
		tmp->next = *dest;
		(*dest)->prev = tmp;
		*dest = tmp;
	}
	opmsg(data, type);
}
