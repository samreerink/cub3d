/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   movement_keys.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/09 18:31:46 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 18:32:30 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	w_input(double move_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;

	p = cube->player;
	m = cube->map;
	if (m[(int)(p->pos_y + p->dir_x * move_speed)][(int)p->pos_x] != '1')
		p->pos_y += p->dir_x * move_speed;
	if (m[(int)p->pos_y][(int)(p->pos_x + p->dir_y * move_speed)] != '1')
		p->pos_x += p->dir_y * move_speed;
}

void	s_input(double move_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;

	p = cube->player;
	m = cube->map;
	if (m[(int)(p->pos_y - p->dir_x * move_speed)][(int)p->pos_x] != '1')
		p->pos_y -= p->dir_x * move_speed;
	if (m[(int)p->pos_y][(int)(p->pos_x - p->dir_y * move_speed)] != '1')
		p->pos_x -= p->dir_y * move_speed;
}

void	a_input(double move_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;

	p = cube->player;
	m = cube->map;
	if (m[(int)(p->pos_y - p->plane_x * move_speed)][(int)p->pos_x] != '1')
		p->pos_y -= p->plane_x * move_speed;
	if (m[(int)p->pos_y][(int)(p->pos_x - p->plane_y * move_speed)] != '1')
		p->pos_x -= p->plane_y * move_speed;
}

void	d_input(double move_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;

	p = cube->player;
	m = cube->map;
	if (m[(int)(p->pos_y + p->plane_x * move_speed)][(int)p->pos_x] != '1')
		p->pos_y += p->plane_x * move_speed;
	if (m[(int)p->pos_y][(int)(p->pos_x + p->plane_y * move_speed)] != '1')
		p->pos_x += p->plane_y * move_speed;
}
