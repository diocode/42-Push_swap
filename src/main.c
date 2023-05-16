/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:59:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/16 18:23:38 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*node;
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
	while (args[i])
	{
		node = ps_lstnew((void *)(long)ft_atoi(args[i++]));
		ps_lstadd_back(stack, node);
	}
	if (ac == 2)
		free_array(args);
}

int	main(int ac, char **av)
{
	t_stack	**a_stack;
	t_stack	**b_stack;

	if (ac < 2)
		return (1);
	if (check_args(ac, av))
		return (1);
	a_stack = malloc(sizeof(t_stack *));
	b_stack = malloc(sizeof(t_stack *));
	if (!a_stack || !b_stack)
	{
		free_data(a_stack, b_stack);
		return (1);
	}
	*a_stack = NULL;
	*b_stack = NULL;
	init_stack(a_stack, ac, av);
	sort_algo(a_stack, b_stack);
	free_data(a_stack, b_stack);
	return (0);
}
