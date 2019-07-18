/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/18 04:48:26 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_mode(t_all *all)
{
	int		count;

	count = 0;
	while (all->ps.cmds[all->ps.point])
	{
		make_cmd(all, all->ps.cmds[all->ps.point++]);
		count++;
	}
	if (!all->ps.b[0] && is_sorted(all->ps.a))
		ft_printf("%{gre}s\nOperations: %d\n", "OK", count);
	else
		ft_printf("%{red}s\nOperations: %d\n", "KO", count);
}

static void	read_input(t_all *all)
{
	t_list	*tmp;
	char	*line;
	size_t	count;
	int		ret;

	count = 0;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret < 0)
			push_swap_clear_exit(all, CH_INPUT_ERR);
		count += get_cmd(all, &line);
	}
	if (!(all->ps.cmds = (char *)malloc(sizeof(char) * (count + 1))))
		push_swap_clear_exit(all, CH_MEM_ERR);
	all->ps.cmds[count] = 0;
	tmp = all->ps.lst;
	while (tmp)
	{
		all->ps.cmds[count-- - 1] = *(char *)tmp->content;
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	t_all	all;
	int		*tmp_arr;

	ft_bzero(&all, sizeof(t_all));
	all.prog = CHECKER;
	init(&all, ac, av);
	all.is_print = 0;
	check_matches(&all);
	read_input(&all);
	check_sizes(&all);
	if (all.ps.flag)
	{
		read_ini(&all);
		tmp_arr = get_presorted_arr(&all, all.ps.a);
		init_marks_arr(&all, tmp_arr);
		set_marks(all.ps.marks, tmp_arr[0]);
		ft_memdel((void **)&tmp_arr);
		visualisation_init(&all);
		render(&all, START);
		mlx_loop(&all.mlx.ptr);
	}
	else
		check_mode(&all);
	return (0);
}
