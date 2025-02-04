/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   key_input.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 17:09:06 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/04 17:55:39 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_input(mlx_key_data_t keydata, void *ptr)
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
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_cube(cube);
	// Keys A and D are temp, need to study the code
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		if (m[(int)(p->pos_y + p->dir_x * move_speed)][(int)p->pos_x] != '1')
			p->pos_y += p->dir_x * move_speed;
		if (m[(int)p->pos_y][(int)(p->pos_x + p->dir_y * move_speed)]!= '1')
			p->pos_x += p->dir_y * move_speed;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		if (m[(int)(p->pos_y - p->dir_x * move_speed)][(int)p->pos_x] != '1')
			p->pos_y -= p->dir_x * move_speed;
		if (m[(int)p->pos_y][(int)(p->pos_x - p->dir_y * move_speed)] != '1')
			p->pos_x -= p->dir_y * move_speed;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
		p->dir_y = oldDirX * sin(rot_speed) + p->dir_y * cos(rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
		p->plane_y = oldPlaneX * sin(rot_speed) + p->plane_y * cos(rot_speed);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		double oldDirX = p->dir_x;
		p->dir_x = p->dir_x * cos(-rot_speed) - p->dir_y * sin(-rot_speed);
		p->dir_y = oldDirX * sin(-rot_speed) + p->dir_y * cos(-rot_speed);
		double oldPlaneX = p->plane_x;
		p->plane_x = p->plane_x * cos(-rot_speed) - p->plane_y * sin(-rot_speed);
		p->plane_y = oldPlaneX * sin(-rot_speed) + p->plane_y * cos(-rot_speed);
	}
}
