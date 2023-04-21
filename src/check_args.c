/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:16:38 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/21 16:28:39 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	repeat_nbr(int n, char **args, int i)
{
	while (args[++i])
	{
		if (ft_atoi(args[i]) == n)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

static int	check_nbr(char *n)
{
	int	i;

	i = 0;
	if (n[0] == '-')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i++]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

static void	check_array(char **args, int i)
{
	long	tmp;

	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (check_nbr(args[i]))
			return ;
		if (repeat_nbr((int)tmp, args, i))
			return ;
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\n", 6);
			return ;
		}
		i++;
	}
}

void	check_args(int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	check_array(args, i);
	if (ac == 2)
	{
		free_array(args);
		free(args);
	}
}
