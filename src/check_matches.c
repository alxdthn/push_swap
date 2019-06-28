/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:08:39 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 02:09:29 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_matches(int *a)
{
	size_t	i;
	size_t	j;
	int		value;

	i = 1;
	while (i < a[0] + 1)
	{
		j = i;
		value = a[i];
		while (j < a[0])
		{
			if (value == a[j + 1])
				return (ft_puterr(0, "Matches forbidden!\n"));
			j++;
		}
		i++;
	}
	return (1);
}
