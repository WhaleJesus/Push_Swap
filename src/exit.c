/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:36:48 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:36:49 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	exit_msg(char *msg)
{
	(void)msg;
	ft_printf("Error\n");
	exit(1);
}

void	free_stack(t_stack **stack, int error, char *msg)
{
	t_stack	*tmp;
	t_stack	*node;

	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	if (error)
		exit_msg(msg);
}

void	free_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	if (av)
		free (av);
}

void	exit_program(t_data *data, char **av)
{
	if (data->debug)
	{
		print_stack(&data->a);
		if (is_sorted(&data->a))
			ft_printf("stack sorted\n");
		else
			ft_printf("stack not sorted tf\n");
		ft_printf("Total operations: %d\n", data->op_count);
		ft_printf("pa: %i pb: %i\n", data->pa, data->pb);
		ft_printf("sa: %i sb: %i ss: %i\n", data->sa, data->sb, data->ss);
		ft_printf("ra: %i rb: %i rr: %i\n", data->ra, data->rb, data->rr);
		ft_printf("rra: %i rrb: %i rrr: %i\n", data->rra, data->rrb, data->rrr);
	}
	free_stack(&data->a, 0, "");
	free_stack(&data->b, 0, "");
	free_args(av);
	exit(0);
	push_back_to_a2(data);
}
