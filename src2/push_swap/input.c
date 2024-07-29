/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:41:06 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/29 21:02:17 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ps.h"

void	check_input(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 0;
		while (*argv[i])
		{
			if ((!ft_isdigit(*argv[i])) && *argv[i] != " ")
					exit_program("Please provide only numbers");
			i++;
		}
		argv++;
	}
}
