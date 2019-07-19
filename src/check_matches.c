/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:08:39 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:52:30 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_matches(t_all *all)
{
	int		i;
	int		j;
	int		value;

	i = 1;
	while (i < all->ps.a[0] + 1)
	{
		j = i;
		value = all->ps.a[i];
		while (j < all->ps.a[0])
		{
			if (value == all->ps.a[j + 1])
				all->exit_function(all, ERROR);
			j++;
		}
		i++;
	}
	return ;
}
