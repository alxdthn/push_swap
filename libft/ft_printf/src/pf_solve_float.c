/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:10:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:03:47 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_ldbl(t_res *res, t_ems *uni, char type)
{
	if (uni->ems.e == 0x7FFF)
	{
		res->len = 3;
		if (uni->ems.m >> 62 == 0)
		{
			if (uni->ems.m == 0)
				res->str = (type == 'f') ? ft_strdup("inf") : ft_strdup("INF");
			else
				res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		}
		else if (uni->ems.m >> 62 == 2)
		{
			if (uni->ems.m << 2 == 0)
				res->str = (type == 'f') ? ft_strdup("inf") : ft_strdup("INF");
			else
				res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		}
		else if (uni->ems.m >> 62 == 1 || uni->ems.m >> 62 == 3)
			res->str = (type == 'f') ? ft_strdup("nan") : ft_strdup("NAN");
		if (!res->str)
			res->len = -1;
	}
}

static void	set_params_float(t_res *res, t_ems *uni, t_task *task)
{
	if (res->str[0] == 'n' || res->str[0] == 'N')
	{
		task->flags.plus = 0;
		task->flags.zero = 0;
		task->flags.space = 0;
		uni->ems.s = 0;
	}
	if (res->str[0] == 'i' || res->str[0] == 'I')
		task->flags.zero = 0;
	task->prc = -1;
	if (res->str && (task->flags.plus || task->flags.space || uni->ems.s))
		set_sign(res, task, -uni->ems.s);
	if (res->str && task->flags.zero && task->width > res->len)
		set_zero(res, task->width);
	else if (task->width > res->len)
		set_width(res, task, ' ');
}

t_res		solve_float(t_task *task, va_list *args)
{
	long double	ldbl;
	t_ems		uni;
	t_res		res;

	if (task->size.chr == 'f')
		ldbl = va_arg(*args, long double);
	else
		ldbl = va_arg(*args, double);
	uni.ldbl = ldbl;
	res.len = 0;
	res.str = NULL;
	check_ldbl(&res, &uni, task->type);
	if (task->prc)
		task->prc = (task->prc == -1) ? 7 : ++task->prc;
	if (!res.str && res.len != -1)
		get_ldbl(&res, task, &uni);
	if (res.len != -1)
		set_params_float(&res, &uni, task);
	return (res);
}
