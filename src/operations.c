/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:16:05 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/28 19:01:48 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first 2 elements at the top of stack */
static int	swap(t_stack **stack)
{
	void	*content;

	if ((*stack) && (*stack)->next)
	{
		content = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = content;
		return (1);
	}
	return (0);
}

/* Take the first element at the top and put it at the top of the other stack */
static int	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*node_1;
	t_stack	*node_2;

	if ((*stack1))
	{
		node_1 = (*stack1);
		node_2 = ps_lstnew((*stack1)->content);
		if ((*stack2))
			ps_lstadd_front(stack2, node_2);
		else
			(*stack2) = node_2;
		(*stack1) = (*stack1)->next;
		free(node_1);
		return (1);
	}
	return (0);
}

/* Shift UP all elements of a stack by 1 */
static int	rotate(t_stack **stack)
{
	t_stack	*node;

	if ((*stack))
	{
		node = (*stack);
		(*stack) = (*stack)->next;
		ps_lstadd_back(stack, node);
		node->next = NULL;
	}
	return (1);
}

/* Shift DOWN all elements of a stack by 1 */
static int	rev_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	if ((*stack))
	{
		tmp = (*stack);
		while (tmp->next->next)
			tmp = tmp->next;
		node = ps_lstlast((*stack));
		ps_lstadd_front(stack, node);
		tmp->next = NULL;
	}
	return (1);
}

/*Choose and exec. the operations*/
int	operation(t_stack **a_stack, t_stack **b_stack, char *op)
{
	int	success;

	success = 0;
	if (ft_strncmp("sa", op, 3) == 0)
		success = swap(a_stack);
	else if (ft_strncmp("sb", op, 3) == 0)
		success = swap(b_stack);
	else if (ft_strncmp("ss", op, 3) == 0)
	{
		success = swap(a_stack);
		success = swap(b_stack);
	}
	if (ft_strncmp("pa", op, 3) == 0)
		success = push(b_stack, a_stack);
	else if (ft_strncmp("pb", op, 3) == 0)
		success = push(a_stack, b_stack);
	if (ft_strncmp("ra", op, 3) == 0)
		success = rotate(a_stack);
	else if (ft_strncmp("rb", op, 3) == 0)
		success = rotate(b_stack);
	else if (ft_strncmp("rr", op, 3) == 0)
	{
		success = rotate(a_stack);
		success = rotate(b_stack);
	}
	if (ft_strncmp("rra", op, 4) == 0)
		success = rev_rotate(a_stack);
	else if (ft_strncmp("rrb", op, 4) == 0)
		success = rev_rotate(b_stack);
	else if (ft_strncmp("rra", op, 4) == 0)
	{
		success = rev_rotate(a_stack);
		success = rev_rotate(b_stack);
	}
	if (success)
	{
		ft_printf("%s\n", op);
		return (0);
	}
	return (1);
}
