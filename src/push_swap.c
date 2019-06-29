/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 23:34:13 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	auto_mode(t_ps *ps)
{
	t_info	info;
	char	*cmd;

	if (ps->flag)
	{
		ft_putstr("Init arrs:\n");
		print_arr(ps->a, ps->b);
	}
	while (ps->b[0] || !is_sorted(ps->a))
	{
		while (ps->a[0] != 1 && !is_sorted(ps->a))
		{
			get_info(&info, ps->a);
			if (info.min_adr == ps->a[0])
				cmd = "pb\n";
			else
				cmd = (ps->a[0] / 2 - info.min_adr < 0) ? "ra\n" : "rra\n";
			process_cmd(ps, cmd);
			ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
		}
		while (ps->b[0])
		{
			cmd = "pa\n";
			process_cmd(ps, cmd);
			ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
		}
	}
}

static char	*get_cmd(void)
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

static void	handle_mode(t_ps *ps)
{
	char	*cmd;

	ft_putstr("Init arrs:\n");
	print_arr(ps->a, ps->b);
	while (42)
	{
		cmd = get_cmd();
		if (!ft_strcmp(cmd, "q\n") || !process_cmd(ps, cmd))
		{
			ft_strdel(&cmd);
			break ;
		}
		print_arr(ps->a, ps->b);
		ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
		ft_strdel(&cmd);
	}
}

int		main(int ac, char **av)
{
	t_ps	ps;

	if (init(&ps, ac, av, PS_USAGE))
		return (1);
	if (ps.flag)
	{
		ps.flag = (ps.flag == 'h')
		? ft_puterr('h', "Welcome to handle mode\n")
		: ft_puterr(0, "Unknown flag\n");
	}
	if (check_matches(ps.a))
		(ps.flag) ? handle_mode(&ps) : auto_mode(&ps);
	print_lst(&ps.lst);
	ft_memdel((void **)&ps.a);
	ft_memdel((void **)&ps.b);
	return (0);
}
