/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:00:26 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/01 16:50:50 by digoncal         ###   ########.fr       */
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
	total += (long)node->content;
	return ((void *)(long)(total / stack_len(stack)));
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

void	*find_min(t_list **stack)
{
	t_list	*min;
	t_list	*cmp;
	t_list	*last;

	min = (*stack);
	cmp = min->next;
	last = ft_lstlast((*stack));
	while (min->next && cmp->next)
	{
		if ((int)(long)min->content > (int)(long)cmp->content)
		{
			min = cmp;
			cmp = cmp->next;
		}
		else
			cmp = cmp->next;
	}
	if ((int)(long)min->content > (int)(long)last->content)
		min = last;
	return (min->content);
}

void	min_to_b(t_list **a_stack, t_list **b_stack)
{
	void	*min;

	min = find_min(a_stack);
	while ((int)(long)(*a_stack)->content != (int)(long)min)
	{
		if ((int)(long)(*a_stack)->content != (int)(long)min &&
		(int)(long)(*a_stack)->next->content != (int)(long)min)
			operation(a_stack, b_stack, "rra");
		else
			operation(a_stack, b_stack, "ra");
	}
	operation(a_stack, b_stack, "pb");
}
