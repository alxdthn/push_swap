/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:03:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:00:50 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_sharp_hex(t_res *res, t_task *task)
{
	t_res	tmp;

	if (res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = res->len + 2;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		tmp.str[0] = '0';
		tmp.str[1] = task->type;
		ft_memcpy(tmp.str + 2, res->str, res->len);
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_sharp_octal(t_res *res, t_task *task)
{
	t_res	tmp;

	if ((res->str && res->str[0] == '0') || res->len == -1)
		return ;
	tmp.str = NULL;
	tmp.len = res->len + 1;
	if ((tmp.str = (char *)malloc(sizeof(char) * tmp.len)))
	{
		tmp.str[0] = '0';
		ft_memcpy(tmp.str + 1, res->str, res->len);
		if (task->prc == -1 && task->flags.zero &&
		task->width > res->len && !task->flags.minus)
			set_zero(&tmp, task->width);
	}
	else
		tmp.len = -1;
	ft_strdel(&res->str);
	*res = tmp;
}

static void	set_params(t_res *res, t_task *task, long nbr)
{
	if (res->len != -1)
	{
		if (task->flags.sharp && (task->type == 'o' || task->type == 'O'))
			set_sharp_octal(res, task);
		if (nbr && task->flags.sharp
		&& (task->type == 'x' || task->type == 'X'))
			set_sharp_hex(res, task);
		if ((task->flags.plus || task->flags.space || nbr < 0)
		&& ft_strchr("dDi", task->type))
			set_sign(res, task, nbr);
		if (task->prc == -1 && task->flags.zero && task->width > res->len)
			set_zero(res, task->width);
		else if (task->width > res->len)
			set_width(res, task, ' ');
	}
}

t_res		solve_digit(t_task *task, long arg)
{
	char			base;
	unsigned long	nbr;
	t_res			res;

	res.str = NULL;
	res.len = 0;
	if (!task->prc && !arg)
		set_params(&res, task, arg);
	else
	{
		base = 10;
		if (ft_strchr("oO", task->type))
			base = 8;
		else if (ft_strchr("xX", task->type))
			base = 16;
		if (arg < 0 && ft_strchr("dDi", task->type))
			nbr = -arg;
		else
			nbr = arg;
		res = pf_ltoa_base(nbr, base, task);
		set_params(&res, task, arg);
	}
	return (res);
}
