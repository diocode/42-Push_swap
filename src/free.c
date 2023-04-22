/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:32:59 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:55 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i >= 0)
		free(arr[i--]);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*node;

	node = (*stack);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	free_data(t_list **a_stack, t_list **b_stack)
{
	if (a_stack)
		free_stack(a_stack);
	if (b_stack)
		free_stack(b_stack);
}
