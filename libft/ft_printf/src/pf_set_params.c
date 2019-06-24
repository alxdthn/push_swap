/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:10:39 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 02:06:21 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_sign(t_res *res, t_task *task, long nbr)
{
	t_res	tmp;
	int		i;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = res->len + 1;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		i = 0;
		if (task->flags.space)
			tmp.str[i] = ' ';
		if (task->flags.plus)
			tmp.str[i] = '+';
		if (nbr < 0)
			tmp.str[i] = '-';
		while (i++ < res->len)
			tmp.str[i] = res->str[i - 1];
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

void		set_prc(t_res *res, int prc)
{
	t_res	tmp;

	if (res->len > prc || res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = prc;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		while (res->len)
			tmp.str[prc-- - 1] = res->str[res->len-- - 1];
		while (prc)
			tmp.str[prc-- - 1] = '0';
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_backward(t_res *res, int width, char filler)
{
	t_res	tmp;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = width;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		while (res->len)
			tmp.str[width-- - 1] = res->str[res->len-- - 1];
		while (width)
			tmp.str[width-- - 1] = filler;
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_forward(t_res *res, int width, char filler)
{
	t_res	tmp;
	int		i;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = width;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		i = 0;
		while (i < res->len)
		{
			tmp.str[i] = res->str[i];
			i++;
		}
		while (i < width)
			tmp.str[i++] = filler;
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

void		set_width(t_res *res, t_task *task, char filler)
{
	if (task->flags.minus)
		set_forward(res, task->width, filler);
	else
		set_backward(res, task->width, filler);
}
