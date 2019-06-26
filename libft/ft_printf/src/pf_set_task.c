/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_ftask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:47:20 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:01:56 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_new(t_flags *flags)
{
	flags->sharp = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
}

static void	ftask_new(t_ftask *ftask)
{
	flags_new(&ftask->flags);
	ftask->clr = NULL;
	ftask->size.chr = 0;
	ftask->size.value = sizeof(int);
	ftask->width = 0;
	ftask->prc = -1;
	ftask->type = '\0';
}

void		out_new(t_out *out)
{
	ftask_new(&out->ftask);
	out->res.str = NULL;
	out->res.len = 0;
}
