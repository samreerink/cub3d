/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   key_input.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 17:09:06 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 18:38:18 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_input(void *ptr)
{
	t_cube		*cube;
	double		const_time;
	double		move_speed;
	double		rot_speed;

	cube = (t_cube *)ptr;
	const_time = 0.03;
	move_speed = const_time * 3.0;
	rot_speed = const_time * 2.0;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		exit_cube(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W))
		w_input(move_speed, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S))
		s_input(move_speed, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		a_input(move_speed, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		d_input(move_speed, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		left_input(rot_speed, cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		right_input(rot_speed, cube);
}
