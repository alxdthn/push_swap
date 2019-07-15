/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neibrs_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:44:40 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 21:13:15 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_value_adr(int *arr, int value)
{
	int		adr;

	adr = 1;
	while (adr <= arr[0])
	{
		if (arr[adr] == value)
			return (adr);
		adr++;
	}
	return (0);
}

static void	sort(int *arr)
{
	size_t	i;
	size_t	size;
	int		tmp;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] < arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 1;
			continue ;
		}
		i++;
	}
}

void	get_neibs(t_all *all, t_neibs *cur, int value)
{
	int		i;

	i = 0;
	while (all->ps.neibs[i]->value != value)
		i++;
	cur->down = all->ps.neibs[i]->down;
	cur->up = all->ps.neibs[i]->up;
	cur->value = all->ps.neibs[i]->value;
}

static void	set_color(int size, int *color, int i)
{
	int		delta;

	delta = size / 3;
	if (i < delta)
		*color = BOT_COLOR;
	else if (i < delta * 2)
		*color = MID_COLOR;
	else
		*color = TOP_COLOR;
}

void	find_neibs(t_all *all)
{
	int		*tmp_sort;
	int		i;

	if (!(tmp_sort = ft_memdup(all->ps.a, sizeof(int) * (all->ps.a[0]) + 1)))
		push_swap_clear_exit(all, PS_MEM_ERR);
	if (!(all->ps.neibs = (t_neibs **)ft_memalloc(sizeof(t_neibs *) * (all->ps.a[0] + 1))))
	{
		ft_memdel((void **)&tmp_sort);
		push_swap_clear_exit(all, PS_MEM_ERR);
	}
	all->ps.neibs[all->ps.a[0]] = NULL;
	sort(tmp_sort);
	i = 0;
	while (++i <= all->ps.a[0])
	{
		if (!(all->ps.neibs[i - 1] = (t_neibs *)malloc(sizeof(t_neibs))))
			push_swap_clear_exit(all, PS_MEM_ERR);
		all->ps.neibs[i - 1]->value = tmp_sort[i];
		all->ps.neibs[i - 1]->down = (i == 1) ? tmp_sort[tmp_sort[0]] : tmp_sort[i - 1];
		all->ps.neibs[i - 1]->up = (i == tmp_sort[0]) ? tmp_sort[1] : tmp_sort[i + 1];
		set_color(all->ps.a[0], &all->ps.neibs[i - 1]->color, i);
	}
	ft_memdel((void **)&tmp_sort);
}
