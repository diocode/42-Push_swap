/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:11 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:06 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 1-> Divide the stack in chunks;

 2-> Scan Stack A from the top to confirm if one of the numbers from Chunk 1
	exist inside of it. Let's call that number hold_1.

 3-> Scan Stack A again from the bottom and see if a different number from
	Chunk 1 exists in that list. I’ll call that number hold_2.

 4-> Compare how many moves it would take to get hold_1 and hold_2 to
	the top.

 5->
*/
static t_stack	*lowest_cost(t_stack **stack, t_stack *hold_1, t_stack *hold_2)
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

static void	push_chunk(t_stack **a_stack, t_stack **b_stack, int chunk)
{
	t_stack	*hold_1;
	t_stack	*hold_2;

	hold_1 = (*a_stack);
	while (hold_1->next)
	{
		if (chunk == 1 && (int)(long)hold_1->content <= 19)
			break ;
		hold_1 = hold_1->next;
	}
	hold_2 = ps_lstlast(*a_stack);
	while (hold_2->prev)
	{
		if ((int)(long)hold_2->content <= 19)
			break ;
		hold_2 = hold_2->prev;
	}
	(void)b_stack;
}

void	sort_algo(t_stack **a_stack, t_stack **b_stack)
{
	int	chunk;

	quick_sort(a_stack, b_stack);
	if (is_sorted(a_stack))
		return ;
	chunk = 1;
	if (ps_lstsize(*a_stack) <= 100)
		while (chunk <= 5)
			push_chunk(a_stack, b_stack, chunk++);
}
