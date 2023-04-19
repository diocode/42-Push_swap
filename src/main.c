/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:59:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/19 13:19:44 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack 	**a_stack;
	t_stack 	**b_stack;

	if (ac < 2)
		return (1);
	check_args(ac, av);
	a_stack = malloc(sizeof(t_stack));
	b_stack = malloc(sizeof(t_stack));
	free(a_stack);
	free(b_stack);
	return (0);
}
