/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 08:54:08 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_mode(t_all *all)
{
	int		count;

	count = 0;
	while (all->ps.arr[all->ps.point])
	{
		if (!process_cmd(&all->ps, all->ps.arr[all->ps.point++]))
			push_swap_clear_exit(all, CH_ARG_ERR);
		count++;
	}
	if (!all->ps.b[0] && is_sorted(all->ps.a))
		ft_printf("%{gre}s\nOperations: %d\n", "OK", count);
	else
		ft_printf("%{red}s\nOperations: %d\n", "KO", count);
}

static void		read_input(t_all *all)
{
	t_list	*tmp;
	char	*cmd;
	size_t	count;
	int		ret;

	count = 0;
	//int fd = open("cmds.txt", O_RDONLY);
	while ((ret = get_next_line(0, &cmd)) > 0)
	{
		//ft_printf("%s %d\n", cmd, ft_strlen(cmd));
		if (ret < 0)
			push_swap_clear_exit(all, "checker: Unkcnown error\n");
		ft_lstadd(&all->ps.lst, ft_lstnew(cmd, (ft_strlen(cmd) + 1)));
		//ft_printf("%s\n", all->ps.lst->content);
		ft_strdel(&cmd);
		if (!all->ps.lst || count + 1 == 0)
			push_swap_clear_exit(all, CH_MEM_ERR);
		count++;
	}
	if (!(all->ps.arr = (char **)malloc(sizeof(char *) * (count + 1))))
		push_swap_clear_exit(all, CH_MEM_ERR);
	all->ps.arr[count] = NULL;
	tmp = all->ps.lst;
	while (tmp)
	{
		all->ps.arr[count-- - 1] = (char *)tmp->content;
		tmp = tmp->next;
	}
	//push_swap_clear_exit(all, "DEBUG END\n");
}

int			main(int ac, char **av)
{
	t_all	all;

	all.prog = CHECKER;
	init(&all, ac, av);
	check_matches(&all);
	read_input(&all);
/*
	size_t	i = 0;
	while (all.ps.arr[i])
	{
		ft_printf("%s\n", all.ps.arr[i]);
		i++;
	}
	push_swap_clear_exit(&all, NULL);
*/
	if (all.ps.flag)
	{
		if (all.ps.flag == 'v')
		{
			visualisation_init(&all);
			render(&all.ps, &all.mlx, START);
			mlx_loop(&all.mlx.ptr);
		}
		else
			all.ps.flag = ft_puterr(0, CH_FLAG_ERR);
	}
	else
		check_mode(&all);
	return (0);
}
