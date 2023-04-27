/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:00:26 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/27 17:02:27 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	stack_len(t_list **stack)
{
	t_list	*node;
	long	total;

	node = (*stack);
	total = 1;
	while (node->next)
	{
		node = node->next;
		total++;
	}
	return (total);
}

void	*average(t_list **stack)
{
	t_list	*node;
	long	total;

	node = (*stack);
	total = 0;
	while (node->next)
	{
		total += (long)node->content;
		node = node->next;
	}
	return ((void *)(long)(total / 2));
}

int	is_sorted(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	while (node->next && node->content < node->next->content)
		node = node->next;
	if (node->next)
		return (0);
	return (1);
}
