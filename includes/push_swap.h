/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:52:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/21 16:35:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ---------- LIBRARIES ---------- */

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/* ---------- STRUCS ---------- */

/*---------- FUNCTIONS ----------*/

void	init_stack(t_list **stack, int ac, char **av);

//utils
void	check_args(int ac, char **av);

//free
void	free_array(char **arr);

#endif