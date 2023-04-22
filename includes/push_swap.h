/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/22 17:23:08 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include "libft.h"

/*---------- FUNCTIONS ----------*/

int		swap(t_list **a_stack, t_list **b_stack, char op);
int		push(t_list **a_stack, t_list **b_stack, char op);
int		rotate(t_list **a_stack, t_list **b_stack, char op);
int		rev_rotate(t_list **a_stack, t_list **b_stack, char op);

//utils
int		check_args(int ac, char **av);

//free
void	free_array(char **arr);
void	free_stack(t_list **stack);
void	free_data(t_list **a_stack, t_list **b_stack);

#endif