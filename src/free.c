/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:32:59 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/02 15:57:44 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	node = (*stack);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	free_data(t_stack **a_stack, t_stack **b_stack)
{
	if (a_stack)
		free_stack(a_stack);
	if (b_stack)
		free_stack(b_stack);
}
