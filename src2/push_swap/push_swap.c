/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:04:30 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/29 20:40:56 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	if (argc < 4)
		exit_program("wrong number of args\n");
	check_input(argv);
