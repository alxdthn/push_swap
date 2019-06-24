/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:30:06 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 07:31:17 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	validation_task(t_task *task)
{
	if (task->flags.minus)
		task->flags.zero = 0;
	if (ft_strchr("%cCsSp", task->type))
	{
		task->flags.sharp = 0;
	}
	if (ft_strchr("oxX", task->type))
	{
		task->flags.space = 0;
		task->flags.plus = 0;
	}
	if (task->type == 'O' || task->type == 'D' || task->type == 'U')
		task->size.chr = 0;
}

static int	get_type(char **fmt, char *type)
{
	if (!ft_strchr(ALL_PARAM, **fmt))
	{
		*type = **fmt;
		(*fmt)++;
		return (1);
	}
	return (0);
}

int			find_type(char *fmt)
{
	int		i;

	i = 0;
	while (fmt[i])
	{
		if (ft_strchr(ALL_PARAM, fmt[i]))
			i++;
		else
		{
			if (ft_strchr(TYPES, fmt[i]))
				return (1);
			return (0);
		}
	}
	return (0);
}

static int	parse_task(char **fmt, t_task *task, va_list *args)
{
	int		ret;

	ret = 0;
	while (**fmt)
	{
		if (**fmt == '{')
		{
			ret += parse_color(fmt, task, args);
			if (**fmt == '%')
				break ;
		}
		if (get_type(fmt, &task->type) || task->type)
			break ;
		if (get_flags(**fmt, task))
			(*fmt)++;
		if (**fmt != '0' && (ft_isdigit(**fmt) || **fmt == '*'))
			get_width(fmt, task, args);
		if (**fmt == '.')
			get_prc(fmt, &task->prc, args);
		get_size(fmt, &task->size);
	}
	validation_task(task);
	return (ret);
}

int			parse(char **fmt, t_out *out, va_list *args)
{
	int		ret;

	ret = 0;
	if ((out->res.len = ft_strclen(*fmt, '%')))
	{
		write(1, *fmt, out->res.len);
		(*fmt) += out->res.len;
	}
	if (**fmt == '%')
	{
		(*fmt)++;
		if (**fmt)
			ret = parse_task(fmt, &out->task, args);
	}
	return (ret);
}
