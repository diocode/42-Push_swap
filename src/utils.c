/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:00:26 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/28 18:42:51 by digoncal         ###   ########.fr       */
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
	while (node->next && (int)(long)node->content <
		(int)(long)node->next->content)
		node = node->next;
	if (node->next)
		return (0);
	return (1);
}

void	small_first(t_list **a_stack)
{
	t_list	*node;

	while ((int)(long)(*a_stack)->content >
	(int)(long)(*a_stack)->next->content)
		operation(a_stack, NULL, "ra");
	node = (*a_stack);
	while (node->next)
	{
		node = node->next;
		if ((int)(long)(*a_stack)->content > (int)(long)node->content)
		{
			operation(a_stack, NULL, "ra");
			small_first(a_stack);
			return ;
		}
	}
}
