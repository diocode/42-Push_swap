/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:11 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/09 18:27:14 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	cost_b2(t_stack *node, t_stack **b_stack)
{
	int		moves;
	t_stack	*tmp;

	moves = 1;
	tmp = (*b_stack)->next;
	if ((int)(long)node->content < (int)(long)(*b_stack)->content
		&& (int)(long)ps_lstlast(*b_stack)->content ==
		(int)(long)find_min(b_stack))
		return (0);
	while (tmp->next && !((int)(long)node->content < (int)(long)tmp->content
	&& (int)(long)node->content > (int)(long)tmp->prev->content))
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves >= ps_lstsize(*b_stack) / 2)
		moves = ps_lstsize(*b_stack) - moves;
	return (moves);
}

static int	cost_b1(t_stack *node, t_stack **b_stack)
{
	int		moves;
	t_stack	*tmp;

	moves = 0;
	tmp = (*b_stack);
	if ((int)(long)node->content > (int)(long)find_max(b_stack)
	|| (int)(long)node->content < (int)(long)find_min(b_stack))
	{
		if ((int)(long)ps_lstlast(*b_stack)->content ==
		(int)(long)find_min(b_stack) && ps_lstsize(*b_stack) == 2)
			return (0);
		while (tmp->next
			&& (int)(long)tmp->content != (int)(long)find_min(b_stack))
		{
			moves++;
			tmp = tmp->next;
		}
		if (moves >= ps_lstsize(*b_stack) / 2)
			moves = ps_lstsize(*b_stack) - moves;
	}
	else
		moves = cost_b2(node, b_stack);
	return (moves);
}

static int	cost_a(t_stack *node, t_stack **a_stack)
{
	t_stack		*tmp;
	int			moves;

	tmp = (*a_stack);
	moves = 0;
	while ((int)(long)node->content != (int)(long)tmp->content)
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves >= ps_lstsize(*a_stack) / 2)
		moves = ps_lstsize(*a_stack) - moves;
	return (moves);
}

static t_stack	*lowest_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*tmp;
	int		lowest_cost;
	int		moves;

	node = (*a_stack);
	tmp = (*a_stack);
	lowest_cost = INT_MAX;
	while (tmp)
	{
		moves = cost_a(tmp, a_stack) + cost_b1(tmp, b_stack);
		if (lowest_cost > moves)
		{
			lowest_cost = moves;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

static char *sort_b2(t_stack *node, t_stack **b_stack)
{
	int		moves;
	t_stack	*tmp;

	moves = 1;
	tmp = (*b_stack)->next;
	if ((int)(long)node->content < (int)(long)(*b_stack)->content
		&& (int)(long)ps_lstlast(*b_stack)->content ==
		(int)(long)find_min(b_stack))
		return (NULL);
	while (tmp->next && !((int)(long)node->content < (int)(long)tmp->content
	&& (int)(long)node->content > (int)(long)tmp->prev->content))
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves >= ps_lstsize(*b_stack) / 2)
		return ("rrb");
	return ("rb");
}

static void	sort_b1(t_stack *node, t_stack **a_stack, t_stack **b_stack)
{
	int		moves;
	t_stack	*tmp;
	char	*op;

	moves = 0;
	tmp = (*b_stack);
	if ((int)(long)node->content > (int)(long)find_max(b_stack)
		|| (int)(long)node->content < (int)(long)find_min(b_stack))
	{
		if ((int)(long)ps_lstlast(*b_stack)->content ==
			(int)(long)find_min(b_stack) && ps_lstsize(*b_stack) == 2)
			return ;
		while (tmp->next
			&& (int)(long)tmp->content != (int)(long)find_min(b_stack))
		{
			moves++;
			tmp = tmp->next;
		}
		if (moves >= ps_lstsize(*b_stack) / 2)
			op = "rrb";
		op = "rb";
	}
	else
	{
		op = sort_b2(node, b_stack);
		moves = cost_b1(node, b_stack);
	}
	if (!op)
		return ;
	while (moves--)
		operation(a_stack, b_stack, op);
}

static void	push_b(t_stack *node, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;
	int		moves;
	char	*op;

	tmp = (*a_stack);
	moves = 0;
	while ((int)(long)node->content != (int)(long)tmp->content)
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves >= ps_lstsize(*a_stack) / 2)
		op = "rra";
	op = "ra";
	while ((int)(long)node->content != (int)(long)(*a_stack)->content)
		operation(a_stack, b_stack, op);
	sort_b1(node, a_stack, b_stack);
	operation(a_stack, b_stack, "pb");
}

static void	push_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	int		pos;
	char	*op;

	node = (*b_stack);
	pos = 0;
	while ((int)(long)node->content != (int)(long)find_max(b_stack))
	{
		pos++;
		node = node->next;
	}
	if (pos >= ps_lstsize(*b_stack) / 2)
		op = "rrb";
	op = "rb";
	while ((int)(long)(*b_stack)->content != (int)(long)find_max(b_stack))
		operation(a_stack, b_stack, op);
	operation(a_stack, b_stack, "pa");
}

void	sort_algo(t_stack **a_stack, t_stack **b_stack)
{
	int	size;

	quick_sort(a_stack, b_stack);
	if (is_sorted(a_stack))
		return ;
	operation(a_stack, b_stack, "pb");
	operation(a_stack, b_stack, "pb");
	if ((int)(long)(*b_stack)->content < (int)(long)(*b_stack)->next->content)
		operation(a_stack, b_stack, "rb");
	size = ps_lstsize(*a_stack);
	while (size--)
		push_b(lowest_cost(a_stack, b_stack), a_stack, b_stack);
	size = ps_lstsize(*b_stack);
	while (size--)
		push_a(a_stack, b_stack);
}
