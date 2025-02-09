/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   raycasting.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/24 18:28:13 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 16:53:34 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calc_deltadist(t_rays *r)
{
	if (r->raydir_x == 0)
		r->delta_distx = INFINITY;
	else
		r->delta_distx = fabs(1 / r->raydir_x);
	if (r->raydir_y == 0)
		r->delta_disty = INFINITY;
	else
		r->delta_disty = fabs(1 / r->raydir_y);
}

static void	calc_step_and_sidedist(t_rays *r, t_player *p)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->side_distx = (p->pos_y - r->map_y) * r->delta_distx;
	}
	else
	{
		r->step_x = 1;
		r->side_distx = (r->map_y + 1.0 - p->pos_y) * r->delta_distx;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->side_disty = (p->pos_x - r->map_x) * r->delta_disty;
	}
	else
	{
		r->step_y = 1;
		r->side_disty = (r->map_x + 1.0 - p->pos_x) * r->delta_disty;
	}
}

static void	dda_algorithm(char **map, t_rays *r)
{
	while (1)
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			r->map_y += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->map_x += r->step_y;
			r->side = 1;
		}
		if (map[r->map_y][r->map_x] == '1')
			break ;
	}
}

void	raycasting(t_cube *cube)
{
	int			x;
	t_rays		*r;
	t_player	*p;

	x = 0;
	r = cube->rays;
	p = cube->player;
	while (x < WIDTH)
	{
		r->map_y = (int)p->pos_y;
		r->map_x = (int)p->pos_x;
		r->camera_x = 2 * x / (double)WIDTH - 1;
		r->raydir_x = p->dir_x + p->plane_x * r->camera_x;
		r->raydir_y = p->dir_y + p->plane_y * r->camera_x;
		calc_deltadist(r);
		calc_step_and_sidedist(r, p);
		dda_algorithm(cube->map, r);
		if (r->side == 0)
			r->perp_walldist = (r->side_distx - r->delta_distx);
		else
			r->perp_walldist = (r->side_disty - r->delta_disty);
		draw_wall_line(x, cube);
		x++;
	}
}
