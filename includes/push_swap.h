/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/19 13:14:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/* ---------- STRUCS ---------- */

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

/*---------- FUNCTIONS ----------*/

//utils
void	check_args(int ac, char **av);
void	exit_msg(char *msg);

//free
void	free_array(char **arr);

#endif