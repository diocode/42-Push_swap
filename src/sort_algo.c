/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:11 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/16 16:25:58 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	order_stack(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	int		mv;
	char	*op;

	while (ps_lstsize(*b_stack))
	{
		node = (*b_stack);
		mv = 0;
		while ((int)(long)node->content != (int)(long)find_max(b_stack))
		{
			mv++;
			node = node->next;
		}
		if (mv >= ps_lstsize(*b_stack) / 2)
			op = "rrb";
		else
			op = "rb";
		while ((int)(long)(*b_stack)->content != (int)(long)find_max(b_stack))
			operation(a_stack, b_stack, op);
		operation(a_stack, b_stack, "pa");
	}
}

static void	push_to_b(t_stack *node, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;
	int		mv;
	char	*op;

	tmp = (*a_stack);
	mv = 0;
	while (tmp->next && (int)(long)node->content != (int)(long)tmp->content)
	{
		mv++;
		tmp = tmp->next;
	}
	if (mv >= ps_lstsize(*a_stack) / 2)
	{
		op = "rra";
		mv = ps_lstsize(*a_stack) - mv;
	}
	else
		op = "ra";
	while (mv--)
		operation(a_stack, b_stack, op);
	operation(a_stack, b_stack, "pb");
}

static void	push_chunk(t_stack **a_stack, t_stack **b_stack, int chunk_range)
{
	t_stack	*node;
	int		max;
	int		min;

	if (!(*a_stack))
		return ;
	max = (int)(long)find_min(a_stack) + chunk_range;
	min = (int)(long)find_min(a_stack);
	node = (*a_stack);
	while (node)
	{
		if ((int)(long)node->content < max
			&& (int)(long)node->content >= min)
		{
			push_to_b(lowest_cost(a_stack, max, min), a_stack, b_stack);
			node = (*a_stack);
		}
		else
			node = node->next;
	}
}

void	sort_algo(t_stack **a_stack, t_stack **b_stack)
{
	int	i;
	int	chunk_amount;
	int	chunk_range;
	int	count;

	quick_sort(a_stack, b_stack);
	if (is_sorted(a_stack))
		return ;
	i = 0;
	count = ps_lstsize(*a_stack);
	if (count > 100)
		chunk_amount = count / 30;
	else
		chunk_amount = count / 10;
	chunk_range = ((int)(long)find_max(a_stack) / chunk_amount) + 1;
	while (++i <= chunk_amount)
		push_chunk(a_stack, b_stack, chunk_range);
	order_stack(a_stack, b_stack);
}
