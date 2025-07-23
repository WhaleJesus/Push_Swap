/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:36:55 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:36:56 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

t_stack	*get_last(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_node(t_stack **stack, int i)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = i;
	new->prev = NULL;
	new->next = NULL;
	if (!*stack)
		(*stack) = new;
	else
	{
		last = get_last(stack);
		last->next = new;
		new->prev = last;
	}
}

int	stacklen(t_stack **stack)
{
	int		i;
	t_stack	*node;

	i = 0;
	if (NULL != stack)
	{
		node = (*stack);
		while (node)
		{
			i++;
			node = node->next;
		}
	}
	return (i);
}

int	check_duplicate(t_stack **a, int i)
{
	t_stack	*node;

	node = (*a);
	while (node)
	{
		if (node->num == i)
			return (1);
		node = node->next;
	}
	return (0);
}

void	init_stack(t_stack **a, char **av)
{
	long	i;
	int		j;

	if (!a)
		return ;
	j = 1;
	while (av[j])
	{
		i = ft_atol(av[j]);
		if (i < INT_MIN || i > INT_MAX)
		{
			free_args(av);
			free_stack(a, 1, "int over/underflow");
		}
		else if (check_duplicate(a, (int)i))
		{
			free_args(av);
			free_stack(a, 1, "duplicate numbers");
		}
		add_node(a, (int)i);
		j++;
	}
}
