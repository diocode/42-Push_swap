/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/05/02 13:55:16 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include "libft.h"
# include <limits.h>

/*------------- Strutures ---------------*/

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*---------- FUNCTIONS ----------*/

int		operation(t_stack **stack1, t_stack **stack2, char *op);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_algo(t_stack **a_stack, t_stack **b_stack);
void	sort_2(t_stack **a_stack);
void	sort_3(t_stack **a_stack);
void	sort_5(t_stack **a_stack, t_stack **b_stack);

//utils
int		check_args(int ac, char **av);
int		is_sorted(t_stack **stack);
void	*find_min(t_stack **stack);
void	*find_max(t_stack **stack);

//free
void	free_array(char **arr);
void	free_stack(t_stack **stack);
void	free_data(t_stack **a_stack, t_stack **b_stack);

//lists
void	ps_lstadd_front(t_stack **lst, t_stack *new);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstnew(void *content);
t_stack	*ps_lstlast(t_stack *lst);
int		ps_lstsize(t_stack *lst);

/*dev test*/
void	print_stacks(t_stack **a_stack, t_stack **b_stack);

#endif