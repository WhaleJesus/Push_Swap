/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:01 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:37:03 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

char	**split_args(char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**strarr;

	i = 0;
	str = ft_strdup(av[i]);
	while (av[++i])
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
	}
	strarr = ft_split(str, ' ');
	free(str);
	return (strarr);
}

void	check_input(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			while (av[j][i] == ' ')
				i++;
			if ((av[j][i] == '-' || av[j][i] == '+') && i == 0)
				i++;
			if (!ft_isdigit(av[j][i]))
			{
				free_args(av);
				exit_msg("only positive or negative integers");
			}
			i++;
		}
		j++;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
