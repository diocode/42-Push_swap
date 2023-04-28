/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:59:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/28 12:30:23 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*dev test*/
void	print_stacks(t_list **a_stack, t_list **b_stack)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = (*a_stack);
	node_b = (*b_stack);
	ft_printf("\t \t \n");
	ft_printf("\t  A\t B\n");
	ft_printf("\t-----  -----\n");
	while (node_a || node_b)
	{
		if (node_a && node_b)
			ft_printf("\t  %d\t %d\n", (long)node_a->content, (long)
				node_b->content);
		else if (node_a)
			ft_printf("\t  %d\t  \n", (int)(long)node_a->content);
		else if (node_b)
			ft_printf("\t   \t %d\n", (int)(long)node_b->content);
		if (node_a && node_a->next)
			node_a = node_a->next;
		else
			node_a = 0;
		if (node_b && node_b->next)
			node_b = node_b->next;
		else
			node_b = 0;
	}
	ft_printf("\t \t \n");
}

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
	if (check_args(ac, av))
		return (1);
	a_stack = malloc(sizeof(t_list *));
	b_stack = malloc(sizeof(t_list *));
	if (!a_stack || !b_stack)
	{
		free_data(a_stack, b_stack);
		return (1);
	}
	*a_stack = NULL;
	*b_stack = NULL;
	init_stack(a_stack, ac, av);
	print_stacks(a_stack, b_stack);  /*dev test*/
	ft_printf("---- Operations ----\n");  /*dev test*/
	small_first(a_stack, b_stack);
	quick_sort(a_stack, b_stack);
	ft_printf("--------------------\n");  /*dev test*/
	print_stacks(a_stack, b_stack);  /*dev test*/
	free_data(a_stack, b_stack);
	return (0);
}
