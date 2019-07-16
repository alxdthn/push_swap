/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:45:07 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 20:20:03 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*get_cmd(char **av)
{
	char	*tmp;
	char	*cmd;

	tmp = ft_strjoin(". ./randomizer.sh ", av[2]);
	cmd = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
	tmp = ft_strjoin(cmd, av[3]);
	ft_strdel(&cmd);
	cmd = ft_strjoin(tmp, "; ./push_swap $ARG | ./checker $ARG >> log.txt; echo $ARG >> log.txt");
	ft_strdel(&tmp);
	return (cmd);
}

int		read_input(char *cmd, int fd, char flag)
{
	size_t	i;
	char	*line;
	int		count;

	system (cmd);
	get_next_line(fd, &line);
	ft_putendl(line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	ft_putendl(line);
	i = 0;
	if (!line)
		exit(EXIT_FAILURE);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	count = ft_atoi(line + i);
	ft_strdel(&line);
	get_next_line(fd, &line);
	if (flag)
		ft_putendl(line);
	ft_strdel(&line);
	return (count);
}

int		main(int ac, char **av)
{
	int				count;
	int				fd;
	int				i;
	int				bar;
	char			*cmd;
	char			flag;
	unsigned long	global;
	int				tests;


	if (ac != 6)
	{
		ft_putendl("usage: ./ps_checker [-y;-n] [min stack value]"\
		"[max stack value] [count of tests] [max count perations]");
		return (0);
	}
	i = ft_atoi(av[4]) - 1;
	system("rm log.txt");
	system("touch log.txt");
	flag = (ft_strequ("-y", av[1])) ? 1 : 0;
	fd = open("log.txt", O_RDWR);
	bar = ft_atoi(av[5]);
	cmd = get_cmd(av);
	count = 0;
	global = 0;
	tests = 0;
	while (count < bar && i--)
	{
		count = read_input(cmd, fd, flag);
		global += count;
		ft_printf("%{gre}d\n", global / ++tests);
	}
}
