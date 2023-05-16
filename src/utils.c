/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:00:26 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/16 15:58:08 by digoncal         ###   ########.fr       */
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

static t_stack	*cost(t_stack **stack, t_stack *hold_1, t_stack *hold_2)
{
	t_stack	*node;
	int		h1;
	int		h2;

	h1 = 0;
	h2 = 0;
	node = (*stack);
	while ((int)(long)node->content != (int)(long)hold_1->content)
	{
		h1++;
		node = node->next;
	}
	if (h1 > ps_lstsize(*stack) / 2)
		h1 = ps_lstsize(*stack) - h1;
	node = (*stack);
	while ((int)(long)node->content != (int)(long)hold_2->content)
	{
		h2++;
		node = node->next;
	}
	if (h2 > ps_lstsize(*stack) / 2)
		h2 = ps_lstsize(*stack) - h2;
	if (h1 > h2)
		return (hold_2);
	return (hold_1);
}

t_stack	*lowest_cost(t_stack **stack, int max, int min)
{
	t_stack	*hold_1;
	t_stack	*hold_2;

	hold_1 = (*stack);
	while (hold_1->next)
	{
		if ((int)(long)hold_1->content < max
			&& (int)(long)hold_1->content >= min)
			break ;
		hold_1 = hold_1->next;
	}
	hold_2 = ps_lstlast(*stack);
	while (hold_2->prev)
	{
		if ((int)(long)hold_2->content < max
			&& (int)(long)hold_2->content >= min)
			break ;
		hold_2 = hold_2->prev;
	}
	return (cost(stack, hold_1, hold_2));
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
