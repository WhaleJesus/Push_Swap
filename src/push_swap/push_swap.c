/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:04:30 by sklaps            #+#    #+#             */
/*   Updated: 2024/08/30 19:00:56 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 4)
		exit_program("Wrong number of args\n");
	check_input(argv);
	ft_printf("input correct");
	init_a(&a, argv + 1);
	ft_printf("init a done");
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			swap_stack(&a, "sa", false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
