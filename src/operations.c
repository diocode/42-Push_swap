/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:16:05 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/24 19:07:47 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first 2 elements at the top of stack */
int	swap(t_list **stack)
{
	void	*content;

	if ((*stack) && (*stack)->next)
	{
		content = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = content;
		return (0);
	}
	return (1);
}

/* Take the first element at the top and put it at the top of the other stack */
int	push(t_list **stack1, t_list **stack2)
{
	t_list	*node_a;
	t_list	*node_b;

	if ((*stack1))
	{
		node_a = (*stack1);
		node_b = ft_lstnew((*stack1)->content);
		if ((*stack2))
			ft_lstadd_front(stack2, node_b);
		else
			(*stack2) = node_b;
		(*stack1) = (*stack1)->next;
		free(node_a);
		return (0);
	}
	return (1);
}

/* Shift UP all elements of a stack by 1 */
int	rotate(t_list **stack, char op)
{
	(void) stack;
	(void) op;
	return (0);
}

/* Shift DOWN all elements of a stack by 1 */
int	rev_rotate(t_list **stack, char op)
{
	(void) stack;
	(void) op;
	return (0);
}
