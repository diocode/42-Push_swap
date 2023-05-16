/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/16 18:27:56 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	if (node && node->next)
		if ((int)(long)node->content > (int)(long)node->next->content)
			operation(stack, NULL, "sa");
}

void	sort_3(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	if ((int)(long)node->next->next->content > (int)(long)node->next->content)
	{
		if ((int)(long)node->next->next->content > (int)(long)node->content)
			operation(stack, NULL, "sa");
		else
			operation(stack, NULL, "ra");
	}
	else
	{
		if ((int)(long)node->next->next->content < (int)(long)node->content)
		{
			if ((int)(long)node->content > (int)(long)node->next->content)
				operation(stack, NULL, "sa");
			operation(stack, NULL, "rra");
		}
		else
		{
			operation(stack, NULL, "sa");
			operation(stack, NULL, "ra");
		}
	}
}

static void	min_to_b(t_stack **a_stack, t_stack **b_stack)
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

void	sort_5(t_stack **a_stack, t_stack **b_stack)
{
	if (ps_lstsize(*a_stack) == 5)
		min_to_b(a_stack, b_stack);
	min_to_b(a_stack, b_stack);
	sort_3(a_stack);
	if (ps_lstsize(*b_stack) == 2)
		operation(a_stack, b_stack, "pa");
	operation(a_stack, b_stack, "pa");
}

void	quick_sort(t_stack **a_stack, t_stack **b_stack)
{
	if (is_sorted(a_stack))
		return ;
	else if (ps_lstsize(*a_stack) == 2)
		sort_2(a_stack);
	else if (ps_lstsize(*a_stack) == 3)
		sort_3(a_stack);
	else if (ps_lstsize(*a_stack) == 4 || ps_lstsize(*a_stack) == 5)
		sort_5(a_stack, b_stack);
}
