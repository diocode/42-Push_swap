/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:07:49 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/19 13:24:46 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rep_nbr(int n, char **args, int i)
{
	while (args[++i])
		if (ft_atoi(args[i]) == n)
			return (1);
	return (0);
}

static int	check_nbr(char *n)
{
	int i;

	i = 0;
	if (n[0] == '-')
		i++;
	while (n[i])
		if (!ft_isdigit(n[i++]))
			return (1);
	return (0);
}

void	check_args(int ac, char **av)
{
	char **args;
	int i;
	int tmp;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else {
		i = 1;
		args = av;
	}
	while (args[i]) {
		tmp = ft_atoi(args[i]);
		if (check_nbr(args[i]))
			exit_msg("Error");
		if (rep_nbr(tmp, args, i))
			exit_msg("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			exit_msg("Error");
		i++;
	}
	if (ac == 2)
	{
		free_array(args);
		free(args);
	}
}
