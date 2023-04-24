/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/24 19:07:47 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include "libft.h"

/*---------- FUNCTIONS ----------*/

int		swap(t_list **stack);
int		push(t_list **stack1, t_list **stack2);
int		rotate(t_list **stack, char op);
int		rev_rotate(t_list **stack, char op);

//utils
int		check_args(int ac, char **av);

//free
void	free_array(char **arr);
void	free_stack(t_list **stack);
void	free_data(t_list **a_stack, t_list **b_stack);

#endif