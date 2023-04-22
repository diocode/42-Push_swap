/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:59:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:01 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	test_list(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	ft_printf("%d\n", node->content);
	while (node->next)
	{
		node = node->next;
		ft_printf("%d\n", node->content);
	}
}*/

static void	init_stack(t_list **stack, int ac, char **av)
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

int	main(int ac, char **av)
{
	t_list	**a_stack;
	t_list	**b_stack;

	if (ac < 2)
		return (1);
	check_args(ac, av);
	a_stack = malloc(sizeof(t_list));
	if (!a_stack)
		return (1);
	b_stack = malloc(sizeof(t_list));
	if (!b_stack)
		return (1);
	*a_stack = NULL;
	*b_stack = NULL;
	init_stack(a_stack, ac, av);
//	test_list(a_stack);
	free_data(a_stack, b_stack);
	return (0);
}
