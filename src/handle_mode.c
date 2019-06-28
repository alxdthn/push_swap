/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:29:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 02:02:34 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_cmd(void)
{
	static char **cmds;
	static char	**ptr;
	char		*tmp;

	tmp = NULL;
	if (!cmds)
	{
		if (get_next_line(0, &tmp) <= 0)
			return (NULL);
		cmds = ft_strsplit(tmp, ' ');
		ptr = cmds;
		ft_strdel(&tmp);
	}
	tmp = ft_strjoin(*cmds, "\n");
	free(*cmds);
	cmds++;
	if (!*cmds)
	{
		ft_memdel((void **)&ptr);
		cmds = NULL;
	}
	return (tmp);
}

void	handle_mode(t_ps *ps)
{
	char	*cmd;

	ft_putstr("Init arrs:\n");
	print_arr(ps->a, ps->b);
	while (42)
	{
		cmd = get_cmd();
		if (!ft_strcmp(cmd, "q\n") || !process_cmd(ps, cmd))
		{
			ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
			ft_strdel(&cmd);
			break ;
		}
		ft_strdel(&cmd);
	}
}
