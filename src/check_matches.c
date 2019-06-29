/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:08:39 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 06:36:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_matches(t_all *all)
{
	size_t	i;
	size_t	j;
	int		value;

	i = 1;
	while (i < all->ps.a[0] + 1)
	{
		j = i;
		value = all->ps.a[i];
		while (j < all->ps.a[0])
		{
			if (value == all->ps.a[j + 1])
				push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
				? PS_MATCH_ERR : CH_MATCH_ERR);
			j++;
		}
		i++;
	}
	return ;
}
