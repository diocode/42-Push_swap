/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:32:59 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/19 13:16:28 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	while (i >= 0)
		free(arr[i--]);
}
