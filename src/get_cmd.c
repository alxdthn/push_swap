/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 02:56:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:49:21 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_action(char *cmd, t_task *task, size_t *ofset)
{
	task->action = 0;
	if (*cmd == 's')
		task->action = 's';
	else if (*cmd == 'p')
		task->action = 'p';
	else if (*cmd == 'r' && ft_strclen(cmd, ' ') == 2
	&& (*(cmd + 1) == 'r' || *(cmd + 1) == 'a' || *(cmd + 1) == 'b'))
		task->action = '^';
	else if (*cmd == 'r' && ft_strclen(cmd, ' ') == 3
	&& (*(cmd + 2) == 'r' || *(cmd + 2) == 'a' || *(cmd + 2) == 'b'))
		task->action = 'v';
	if (task->action)
	{
		(*ofset) += (task->action == 'v') ? 2 : 1;
		return (task->is_valid = 1);
	}
	return (task->is_valid = 0);
}

static int	get_stack(char *cmd, t_task *task, size_t *ofset)
{
	task->stack = 0;
	if (*cmd == 'a')
		task->stack = 'a';
	else if (*cmd == 'b')
		task->stack = 'b';
	else if (*cmd == 's' || *cmd == 'r')
		task->stack = 'x';
	if (task->stack)
	{
		(*ofset)++;
		return (task->is_valid = 1);
	}
	return (task->is_valid = 0);
}

char		read_cmd(char *cmd, size_t *ofset)
{
	t_task	task;
	char	ret;

	if (*cmd == 'q')
	{
		(*ofset)++;
		return (QUIT);
	}
	ret = '\0';
	if (!get_action(cmd + *ofset, &task, ofset)
		|| !get_stack(cmd + *ofset, &task, ofset))
		return (0);
	if (task.action == 's')
		ret = read_swap(&task);
	else if (task.action == 'p')
		ret = read_push(&task);
	else if (task.action == '^' || task.action == 'v')
		ret = read_rotate(&task);
	return (ret);
}

size_t		get_cmd(t_all *all, char **line)
{
	char		cmd;
	size_t		ofset;
	size_t		ret;

	ofset = 0;
	ret = 0;
	while ((*line)[ofset])
	{
		if (!(cmd = read_cmd((*line), &ofset)))
			push_swap_clear_exit(all, CH_CMD_ERR);
		ft_lstadd(&all->ps.lst, ft_lstnew(&cmd, sizeof(char)));
		ret++;
		if (!all->ps.lst)
		{
			ft_strdel(line);
			push_swap_clear_exit(all, PS_MEM_ERR);
		}
		while ((*line)[ofset] == ' ')
			ofset++;
	}
	ft_strdel(line);
	return (ret);
}
