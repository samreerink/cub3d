/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   rotate_keys.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/09 18:33:06 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 18:33:40 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	left_input(double rot_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;
	double		old_dir_x;
	double		old_plane_x;

	p = cube->player;
	m = cube->map;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

void	right_input(double rot_speed, t_cube *cube)
{
	t_player	*p;
	char		**m;
	double		old_dir_x;
	double		old_plane_x;

	p = cube->player;
	m = cube->map;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-rot_speed) - p->dir_y * sin(-rot_speed);
	p->dir_y = old_dir_x * sin(-rot_speed) + p->dir_y * cos(-rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-rot_speed) - p->plane_y * sin(-rot_speed);
	p->plane_y = old_plane_x * sin(-rot_speed) + p->plane_y * cos(-rot_speed);
}
