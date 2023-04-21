/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:59:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/21 17:05:37 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
void	test_list(t_list **stack)
{
	int	i;

	i = -1;
	while (++i <= 5)
		ft_printf("%d = ", stack->content);
}
*/
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
	test_list(a_stack);
	free(a_stack);
	free(b_stack);
	return (0);
}
