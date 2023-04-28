/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/28 12:05:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*DONE:

 -> is_sorted() (changed return value)
 -> index() and index.c (change names to ft_sort)
 -> operation()
 -> sort_2
 -> sort_3
 -> utils.c and functions
 -> starting/ testing sorting algorithm

 */

void	sort_2(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	if (node && node->next)
		if (node->content > node->next->content)
			operation(stack, NULL, "sa");
}

void	sort_3(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	if (node->next->next->content > node->next->content)
	{
		if (node->next->next->content > node->content)
			operation(stack, NULL, "sa"); //case 1
		else
			operation(stack, NULL, "ra"); //case 3
	}
	else
	{
		if (node->next->next->content < node->content)
		{
			if (node->content > node->next->content)
				operation(stack, NULL, "sa"); //case 2 - 1/2
			operation(stack, NULL, "rra"); //case 5 & case 2 - 2/2
		}
		else
		{
			operation(stack, NULL, "sa"); //case 4 - 1/2
			operation(stack, NULL, "ra"); //case 4 - 2/2
		}
	}
}

void	sort_5(t_list **a_stack, t_list **b_stack)
{
	small_first(a_stack, b_stack);
	if (stack_len(a_stack) == 5)
	{
		operation(a_stack, b_stack, "pa");
		small_first(a_stack, b_stack);
	}
	operation(a_stack, b_stack, "pa");
	sort_3(a_stack);
	operation(a_stack, b_stack, "pb");
	operation(a_stack, b_stack, "pb");
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
