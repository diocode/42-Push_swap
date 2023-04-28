/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/27 17:01:03 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include "libft.h"

/*---------- FUNCTIONS ----------*/

int		operation(t_list **stack1, t_list **stack2, char *op);
void	quick_sort(t_list **stack_a, t_list **stack_b);
void	sort_algorithm(t_list **a_stack, t_list **b_stack);
void	sort_2(t_list **a_stack);
void	sort_3(t_list **a_stack);
void	sort_5(t_list **a_stack, t_list **b_stack);

//utils
int		check_args(int ac, char **av);
long	stack_len(t_list **stack);
int		is_sorted(t_list **stack);
void	*average(t_list **stack);
void	small_first(t_list **a_stack, t_list **b_stack);


//free
void	free_array(char **arr);
void	free_stack(t_list **stack);
void	free_data(t_list **a_stack, t_list **b_stack);

/*dev test*/
void	print_stacks(t_list **a_stack, t_list **b_stack);

#endif