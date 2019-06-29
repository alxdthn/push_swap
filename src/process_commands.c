/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 23:03:50 by nalexand         ###   ########.fr       */
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

char		read_cmd(char *cmd)
{
	t_task	task;
	char	ret;

	task.is_valid = 0;
	if (!get_action(&cmd, &task)
		|| !get_stack(&cmd, &task))
		return (QUIT);
	if (task.action == 's')
		ret = solve_swap(&task);
	else if (task.action == 'p')
		ret = solve_push(&task);
	else if (task.action == 'r' || task.action == 'v')
		ret = solve_rotate(&task);
	return (ret);
}

void		process_commands(t_ps *ps, char cmd)
{

}