/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:30:42 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/21 16:56:52 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_list **stack, int ac, char **av)
{
	t_list	*node;
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
		node = ft_lstnew((void *)(long)ft_atoi(args[i++]));
		ft_lstadd_back(stack, node);
	}
	if (ac == 2)
	{
		free_array(args);
		free(args);
	}
}