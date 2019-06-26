/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 04:51:02 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_action(char **cmd, t_task *task)
{
	task->action = 0;
	if (**cmd == 's')
		task->action = 's';
	else if (**cmd == 'p')
		task->action = 'p';
	else if (**cmd == 'r' && *(*cmd + 1) != 'r')
		task->action = 'r';
	else if (**cmd == 'r' && *(*cmd + 1) == 'r')
		task->action = 'v';
	if (task->action)
	{
		(*cmd) += (task->action == 'v') ? 2 : 1;
		return (task->is_valid = 1);
	}
	return (task->is_valid = 0);
}

static int	get_stack(char **cmd, t_task *task)
{
	task->stack = 0;
	if (**cmd == 'a')
		task->stack = 'a';
	else if (**cmd == 'b')
		task->stack = 'b';
	else if (**cmd == 's' || **cmd == 'r')
		task->stack = 'x';
	if (task->stack)
	{
		(*cmd)++;
		return (task->is_valid = 1);
	}
	return (task->is_valid = 0);
}

static int	get_task(char **cmd, t_task *task)
{
	while (ft_isalpha(**cmd))
	{
		if (**cmd == 'q')
			return (1);
		if (!get_action(cmd, task) || !get_stack(cmd, task))
			return (0);
	}
	while (**cmd == ' ')
		(*cmd)++;
	if (!task->is_valid)
		ft_putstr("Unknown command!\n");
	return (0);
}

int			process_cmd(int **a, int **b, char **cmd)
{
	t_task	task;
	char	*tmp;

	tmp = *cmd;
	task.is_valid = 0;
	while (*tmp)
	{
		if (get_task(&tmp, &task))
			return (1);
		if (!task.is_valid)
			break ;
		if (task.action == 's')
			solve_swap(a, b, &task);
		else if (task.action == 'p')
			solve_push(a, b, &task);
		else if (task.action == 'r' || task.action == 'v')
		{
			if (solve_rotate(a, b, &task))
				break ;
		}
	}
	ft_strdel(cmd);
	return (0);
}
