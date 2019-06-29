/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 04:18:10 by nalexand         ###   ########.fr       */
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
	else if (**cmd == 's' || **cmd == 'r' || (task->action == 'v' && **cmd == '\n'))
		task->stack = 'x';
	if (task->stack)
	{
		(*cmd)++;
		return (task->is_valid = 1);
	}
	return (task->is_valid = 0);
}

static int	get_task(char *cmd, t_task *task)
{
	if (!get_action(&cmd, task) || !get_stack(&cmd, task))
		return (ft_puterr(0, "Unknown command!\n"));
	return (1);
}

int			process_cmd(t_ps *ps, char *cmd)
{
	t_task	task;
	int		ret;

	task.is_valid = 0;
	if (!(ret = get_task(cmd, &task)))
		return (QUIT);
	if (task.action == 's')
		ret = solve_swap(ps->a, ps->b, &task);
	else if (task.action == 'p')
		ret = solve_push(ps->a, ps->b, &task);
	else if (task.action == 'r' || task.action == 'v')
		ret = solve_rotate(ps->a, ps->b, &task);
	return (ret);
}
