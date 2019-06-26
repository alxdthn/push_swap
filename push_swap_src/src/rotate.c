/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:35:34 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 04:51:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(int **arr, int **tmp)
{
	size_t	i;
	size_t	j;

	j = 2;
	i = 1;
	(*tmp)[(*tmp)[0]] = (*arr)[1];
	while (i < (*tmp)[0])
		(*tmp)[i++] = (*arr)[j++];
}

static void	norm_rotate(int **arr, int **tmp)
{
	size_t	i;
	size_t	j;

	j = 2;
	i = 1;
	(*tmp)[1] = (*arr)[(*arr)[0]];
	while (i < (*tmp)[0])
		(*tmp)[j++] = (*arr)[i++];
}

int			rotate(int **arr, char dir)
{
	int		*tmp;

	if ((*arr)[0] < 2)
		return (0);
	tmp = NULL;
	if (!(tmp = (int *)malloc(sizeof(int) * ((*arr)[0] + 1))))
		return (1);
	tmp[0] = (*arr)[0];
	if (dir == -1)
		rev_rotate(arr, &tmp);
	else
		norm_rotate(arr, &tmp);
	ft_memdel((void **)arr);
	*arr = tmp;
	return (0);
}

int			solve_rotate(int **a, int **b, t_task *task)
{
	int		dir;
	int		ret;

	ret = 0;
	dir = 1;
	if (task->action == 'v')
		dir = -1;
	if (task->stack == 'a')
		ret = rotate(a, dir);
	else if (task->stack == 'b')
		ret = rotate(a, dir);
	else if (task->stack == 'x')
	{
		if ((ret = rotate(a, dir)))
			ret = rotate(b, dir);
	}
	return (ret);
}
