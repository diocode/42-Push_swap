/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/28 19:10:20 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	if (node && node->next)
		if ((int)(long)node->content > (int)(long)node->next->content)
			operation(stack, NULL, "sa");
}

void	sort_3(t_list **stack)
{
	t_list	*node;

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

void	sort_5(t_list **a_stack, t_list **b_stack)
{
	small_first(a_stack);
	operation(a_stack, b_stack, "pb");
	if (stack_len(a_stack) == 4)
	{
		small_first(a_stack);
		operation(a_stack, b_stack, "pb");
	}
	sort_3(a_stack);
	operation(a_stack, b_stack, "pa");
	if (stack_len(a_stack) == 4)
		operation(a_stack, b_stack, "pa");
}

void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	if (is_sorted(a_stack))
		return ;
	if (stack_len(a_stack) == 2)
	{
		sort_2(a_stack);
		return ;
	}
	if (stack_len(a_stack) == 3)
	{
		sort_3(a_stack);
		return ;
	}
	if (stack_len(a_stack) == 4 || stack_len(a_stack) == 5)
	{
		sort_5(a_stack, b_stack);
		return ;
	}
}
