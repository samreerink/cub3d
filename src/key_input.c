/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   key_input.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 17:09:06 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/04 21:06:42 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_input(void *ptr)
{
	t_cube		*cube;
	t_player	*p;
	char		**m;
	double		frame_time;
	double		move_speed;
	double		rot_speed;

	cube = (t_cube *)ptr;
	p = cube->player;
	m = cube->map;
	frame_time = cube->mlx->delta_time;
	move_speed = frame_time * 3.0;
	rot_speed = frame_time * 2.0;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		exit_cube(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
	{
		if (m[(int)(p->pos_y + p->dir_x * move_speed)][(int)p->pos_x] != '1')
			p->pos_y += p->dir_x * move_speed;
		if (m[(int)p->pos_y][(int)(p->pos_x + p->dir_y * move_speed)]!= '1')
			p->pos_x += p->dir_y * move_speed;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
	{
		if (m[(int)(p->pos_y - p->dir_x * move_speed)][(int)p->pos_x] != '1')
			p->pos_y -= p->dir_x * move_speed;
		if (m[(int)p->pos_y][(int)(p->pos_x - p->dir_y * move_speed)] != '1')
			p->pos_x -= p->dir_y * move_speed;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
		p->dir_y = oldDirX * sin(rot_speed) + p->dir_y * cos(rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
		p->plane_y = oldPlaneX * sin(rot_speed) + p->plane_y * cos(rot_speed);
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(-rot_speed) - p->dir_y * sin(-rot_speed);
		p->dir_y = oldDirX * sin(-rot_speed) + p->dir_y * cos(-rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(-rot_speed) - p->plane_y * sin(-rot_speed);
		p->plane_y = oldPlaneX * sin(-rot_speed) + p->plane_y * cos(-rot_speed);
	}
}
