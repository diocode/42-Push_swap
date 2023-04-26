/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/26 16:32:36 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*DONE:

 -> is_sorted() (changed return value)
 -> index() and index.c (change names to ft_sort)
 -> operation()
 -> sort_2
 -> sort_3

 */

static int	is_sorted(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	while (node->next && node->content < node->next->content)
		node = node->next;
	if (node->next)
		return (0);
	return (1);
}

static void	sort_2(t_list **a_stack)
{
	t_list	*node;

	node = (*a_stack);
	if (node && node->next)
		if (node->content > node->next->content)
			operation(a_stack, NULL, "sa");
}

static void	sort_3(t_list **a_stack)
{
	t_list	*node;

	node = (*a_stack);
	if (node->next->next->content > node->next->content)
	{
		if (node->next->next->content > node->content)
			operation(a_stack, NULL, "sa"); //case 1
		else
			operation(a_stack, NULL, "ra"); //case 3
	}
	else
	{
		if (node->next->next->content < node->content)
		{
			if (node->content > node->next->content)
				operation(a_stack, NULL, "sa"); //case 2 - 1/2
			operation(a_stack, NULL, "rra"); //case 5 & case 2 - 2/2
		}
		else
		{
			operation(a_stack, NULL, "sa"); //case 4 - 1/2
			operation(a_stack, NULL, "ra"); //case 4 - 2/2
		}
	}
}

void	ft_sort(t_list **a_stack, t_list **b_stack)
{
	t_list	*node;

	node = (*a_stack);
	if (is_sorted(a_stack))
		return ;
	if (!node->next->next)
	{
		sort_2(a_stack);
		return ;
	}
	if (!node->next->next->next)
	{
		sort_3(a_stack);
		return ;
	}
	(void) b_stack;
}
