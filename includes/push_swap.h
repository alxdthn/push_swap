/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:13:31 by nalexand          #+#    #+#             */
/*   Updated: 2020/01/20 20:55:57 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# define ERROR	"Error"
# define SALUT	"push_swap: Welcome to handle mode"
# define LEFT_BACKGROUND 0x252526
# define RIGHT_BACKGROUND 0x1E1E1E
# define POS_LINE_COLOR 0xC3C39D
# define NEG_LINE_COLOR 0x8FBBD7
# define TOP_COLOR 0xfdfdfd
# define MID_COLOR 0x1c4fbb
# define BOT_COLOR 0xb61b1b
# define ESC 53
# define ENTER 36
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define PUSH_SWAP 22
# define CHECKER 21
# define QUIT -1
# define SA 1
# define SB 2
# define RRA 3
# define RA 5
# define RRB 6
# define RB 8
# define SS 10
# define PA 11
# define PB 12
# define RRR 13
# define RR 15
# define START 42
# define ABS(x) ((x) > 0 ? (x) : -(x))
# define LIMIT 10

typedef struct	s_task
{
	char		stack;
	char		action;
	char		is_valid;
}				t_task;

typedef struct	s_info
{
	int			min_adr;
	int			min_value;
	int			max_adr;
	int			max_value;
	int			abs_max;
}				t_info;

typedef struct	s_oprs
{
	int			pa;
	int			rr;
	int			ra;
	int			rb;
	int			rrr;
	int			rra;
	int			rrb;
	int			count;
}				t_oprs;

typedef struct	s_mark
{
	int			value;
	int			color;
	int			level;
}				t_mark;

typedef struct	s_ps
{
	t_list		*lst;
	t_mark		**marks;
	t_info		info;
	size_t		point;
	char		*cmds;
	size_t		commands_count;
	int			*a;
	int			*b;
	int			size;
	int			max_value;
	int			min_value;
}				t_ps;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	t_img		a;
	t_img		b;
	t_img		logo;
	size_t		line_box_size;
	size_t		line_box_width;
	int			line_color;
	int			bckg_color;
	void		*ptr;
	void		*win;
	char		dir;
	char		working;
	int			width;
	int			height;
	int			elem_width;
	int			elem_height;
	int			ofset;
}				t_mlx;

typedef struct	s_flgs
{
	char		print_cmds : 1;
	char		visu : 1;
	char		good_out : 1;
	char		handle : 1;
	char		rus : 1;
}				t_flgs;

typedef union	u_uniflg
{
	t_flgs		flags;
	char		is_flag;
}				t_uniflg;

typedef struct	s_all
{
	t_ps		ps;
	t_mlx		mlx;
	t_uniflg	u;
	void		(*exit_function)(struct s_all *, char *);
	char		prog;
}				t_all;

void			init(t_all *all, int ac, char **av);
void			push(int *src, int *dst, char cmd, char flag);
void			swap(int *arr, char cmd, char flag);
void			rotate(int *arr, char dir, char cmd, char flag);
char			read_cmd(t_all *all, char *cmd, size_t *ofset);
char			read_push(t_task *task);
char			read_swap(t_task *task);
char			read_rotate(t_task *task);
void			push_swap_clear_exit(t_all *all, char *message);
void			checker_clear_exit(t_all *all, char *message);
void			print_arr(int *a, int *b);
int				is_sorted(int *arr);
int				is_loop_sorted(int *arr, int adr);
void			check_matches(t_all *all);
void			print_lst(t_list *lst);
void			get_info(t_info *info, int *a);
void			visualisation_init(t_all *all);
void			render(t_all *all, char cmd);
size_t			get_cmd(t_all *all, char **line);
void			handle_mode(t_all *all);
void			insert_method(t_all *all);
void			hard_insert_method(t_all *all);

void			make_cmd(t_all *all, char cmd);
void			solve_operations(t_all *all, t_oprs oprs);
void			get_double_rotation(int *a, int *b, int *rr);
int				get_rotation(int *r, int *rr, int size, int adr);

t_mark			get_value_mark(t_mark **marks, int value);
void			init_marks_arr(t_all *all, int *arr);
int				*get_presorted_arr(t_all *all, int *arr);
void			set_marks(t_mark **marks, int size);
void			pull_b_stack(t_all *all);

int				deal_key(int key, t_all *all);
int				loop_hook(t_all *all);
int				key_press(int key, t_all *all);
void			read_ini(t_all *all);
void			check_sizes(t_all *all);

#endif
