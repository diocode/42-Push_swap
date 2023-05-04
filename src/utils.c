/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:00:26 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/02 16:24:35 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	while (node->next && (int)(long)node->content <
		(int)(long)node->next->content)
		node = node->next;
	if (node->next)
		return (0);
	return (1);
}

void	*find_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*cmp;
	t_stack	*last;

	min = (*stack);
	cmp = min->next;
	last = ps_lstlast((*stack));
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

void	*find_max(t_stack **stack)
{
	t_stack	*max;
	t_stack	*cmp;
	t_stack	*last;

	max = (*stack);
	cmp = max->next;
	last = ps_lstlast((*stack));
	while (max->next && cmp->next)
	{
		if ((int)(long)max->content < (int)(long)cmp->content)
		{
			max = cmp;
			cmp = cmp->next;
		}
		else
			cmp = cmp->next;
	}
	if ((int)(long)max->content < (int)(long)last->content)
		max = last;
	return (max->content);
}
