/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:54:44 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/27 17:09:44 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Diogo's algorithm:
1- Find the average;
2 - if above the average -> rotate;
3 - if below the average -> push to b;
4 - repeat the process by doing the average again of A;
5 - stop when sort_3 is possible;*/

static void	sorting(t_list **stack1, t_list **stack2)
{
	t_list	*node;

	node = (*stack1);
	while (node->next)
	{
		if ((int)(long)node->content > (int)(long)average(stack1))
			operation(stack1, stack2, "ra");
		else
			operation(stack1, stack2, "pb");
		node = (*stack1);
		if (node->next)
			node = node->next;
	}
	if (stack_len(stack1) > 3)
		sorting(stack1, stack2);
}

void	sort_algorithm(t_list **a_stack, t_list **b_stack)
{
	sorting(a_stack, b_stack);
	if (stack_len(a_stack) == 3)
		sort_3(a_stack);
	if (stack_len(a_stack) == 2)
		sort_2(a_stack);
}
