/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 08:06:13 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	auto_mode(t_all *all)
{
	t_info	info;
	char	*cmd;

	while (all->ps.b[0] || !is_sorted(all->ps.a))
	{
		while (all->ps.a[0] != 1 && !is_sorted(all->ps.a))
		{
			get_info(&info, all->ps.a);
			if (info.min_adr == all->ps.a[0])
				cmd = "pb\n";
			else
				cmd = (all->ps.a[0] / 2 - info.min_adr < 0) ? "ra\n" : "rra\n";
			process_cmd(&all->ps, cmd);
			ft_lstadd(&all->ps.lst, ft_lstnew(cmd, ft_strlen(cmd)));
			if (!all->ps.lst)
				push_swap_clear_exit(all, PS_MEM_ERR);
		}
		while (all->ps.b[0])
		{
			cmd = "pa\n";
			process_cmd(&all->ps, cmd);
			ft_lstadd(&all->ps.lst, ft_lstnew(cmd, ft_strlen(cmd)));
			if (!all->ps.lst)
				push_swap_clear_exit(all, PS_MEM_ERR);
		}
	}
}

static void	get_cmd(t_all *all, char **cmd)
{
	static char **cmds;
	static char	**ptr;
	char		*tmp;
	int			ret;

	tmp = NULL;
	if (!cmds)
	{
		if ((ret = get_next_line(0, &tmp) < 0))
			push_swap_clear_exit(all, "checker: Uncknown input error\n");
		if (!ret && !tmp)
			return ;
		if (!(cmds = ft_strsplit(tmp, ' ')))
			push_swap_clear_exit(all, PS_MEM_ERR);
		ptr = cmds;
		ft_strdel(&tmp);
	}
	if (!(tmp = ft_strjoin(*cmds, "\n")))
		push_swap_clear_exit(all, PS_MEM_ERR);
	free(*cmds);
	cmds++;
	if (!*cmds)
	{
		ft_memdel((void **)&ptr);
		cmds = NULL;
	}
	*cmd = tmp;
}

static void	handle_mode(t_all *all)
{
	char	*cmd;
	int		ret;

	ft_putstr("Init stacks:\n");
	print_arr(all->ps.a, all->ps.b);
	while (42)
	{
		get_cmd(all, &cmd);
		if (!ft_strcmp(cmd, "q\n"))
		{
			print_lst(&all->ps.lst);
			push_swap_clear_exit(all, NULL);
		}
		ret = process_cmd(&all->ps, cmd);
		if (ret)
		{
			ft_lstadd(&all->ps.lst, ft_lstnew(cmd, ft_strlen(cmd)));
			if (!all->ps.lst)
			{
				ft_strdel(&cmd);
				push_swap_clear_exit(all, PS_MEM_ERR);
			}
		}
		else
			ft_puterr(0, PS_CMD_ERR);
		ft_strdel(&cmd);
		print_arr(all->ps.a, all->ps.b);
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	all.prog = PUSH_SWAP;
	init(&all, ac, av);
	if (all.ps.flag == 'h')
		ft_putstr("push_swap: Welcome to handle mode\n");
	else if (all.ps.flag && all.ps.flag != 'h')
		all.ps.flag = ft_puterr(0, PS_FLAG_ERR);
	check_matches(&all);
	(all.ps.flag) ? handle_mode(&all) : auto_mode(&all);
	print_lst(&all.ps.lst);
	push_swap_clear_exit(&all, NULL);
	return (0);
}
