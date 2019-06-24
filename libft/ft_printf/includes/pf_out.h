/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:18:56 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 05:17:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_OUT_H
# define PF_OUT_H
# include "pf_includes.h"

typedef	struct		s_flags
{
	char			sharp;
	char			zero;
	char			minus;
	char			plus;
	char			space;
}					t_flags;

typedef struct		s_size
{
	char			chr;
	size_t			value;
}					t_size;

typedef struct		s_task
{
	t_flags			flags;
	t_size			size;
	char			*clr;
	int				width;
	int				prc;
	char			type;
}					t_task;

typedef struct		s_res
{
	char			*str;
	size_t			len;
}					t_res;

typedef struct		s_out
{
	t_res			res;
	t_task			task;
}					t_out;

void				out_new(t_out *out);

#endif
