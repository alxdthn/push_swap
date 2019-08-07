/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:41:10 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/02 12:02:47 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_sizes(t_all *all)
{
	get_info(&all->ps.info, all->ps.a);
	if (all->u.flags.visu && all->ps.a[0] > 1275)
	{
		ft_putendl("checker: For visualisation mode maximum 1275 values");
		all->u.flags.visu = 0;
	}
	if (all->u.flags.visu && (all->ps.info.max_value > 1275
	|| all->ps.info.min_value < -1275))
	{
		ft_putendl("checker: For visualisation mode max value = 1275");
		all->u.flags.visu = 0;
	}
}

static void	read_line(t_all *all, int fd, int *res, char *str)
{
	char	*line;

	line = NULL;
	if (get_next_line(fd, &line))
	{
		if (!line)
			all->exit_function(all, ERROR);
		if (!ft_strncmp(line, str, ft_strlen(str)))
		{
			if (ft_isint(line + ft_strlen(str)))
			{
				*res = ft_atoi(line + ft_strlen(str));
				ft_strdel(&line);
				return ;
			}
		}
	}
	if (line)
		ft_strdel(&line);
	all->exit_function(all, ERROR);
}

void		read_ini(t_all *all)
{
	int		fd;

	fd = open("push_swap.ini", O_RDONLY);
	if (fd < 3)
	{
		all->mlx.width = 1000;
		all->mlx.height = 500;
	}
	else
	{
		read_line(all, fd, &all->mlx.width, "width: ");
		read_line(all, fd, &all->mlx.height, "height: ");
		if (all->mlx.width < 300 || all->mlx.height < 300
		|| all->mlx.width > 3000 || all->mlx.height > 3000)
			all->exit_function(all, ERROR);
	}
}

static void	mlx_init_params(t_all *all)
{
	all->mlx.dir = 1;
	all->mlx.ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.ptr,
	all->mlx.width, all->mlx.height, "push_swap by nalexand");
	all->mlx.a.ptr = mlx_new_image(all->mlx.ptr,
	all->mlx.width / 2, all->mlx.height);
	all->mlx.a.data = (int *)mlx_get_data_addr(all->mlx.a.ptr,
	&all->mlx.a.bpp, &all->mlx.a.size_line, &all->mlx.a.endian);
	all->mlx.a.size_line /= 4;
	all->mlx.b.ptr = mlx_new_image(all->mlx.ptr,
	all->mlx.width / 2, all->mlx.height);
	all->mlx.b.data = (int *)mlx_get_data_addr(all->mlx.b.ptr,
	&all->mlx.b.bpp, &all->mlx.b.size_line, &all->mlx.b.endian);
	all->mlx.b.size_line /= 4;
	all->mlx.logo.ptr = mlx_xpm_file_to_image(all->mlx.ptr,
	"src/logo2.xpm", &all->mlx.logo.bpp, &all->mlx.logo.bpp);
}

void		visualisation_init(t_all *all)
{
	mlx_init_params(all);
	mlx_key_hook(all->mlx.win, deal_key, all);
	mlx_loop_hook(all->mlx.ptr, loop_hook, all);
	mlx_hook(all->mlx.win, 2, 0, key_press, all);
	all->mlx.elem_height = (double)all->mlx.height
	/ (double)all->ps.a[0] + 0.5;
	if (all->mlx.elem_height * all->ps.a[0] > all->mlx.height)
		all->mlx.elem_height -= 1;
	all->mlx.elem_width = (double)all->mlx.a.size_line
	/ (double)all->ps.info.max_value + 0.5;
	if (all->mlx.elem_width * all->ps.info.max_value > all->mlx.a.size_line)
		all->mlx.elem_width--;
}
