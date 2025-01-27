/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   raycasting.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/24 18:28:13 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/27 03:09:59 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	testMap[6][11]=
{
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,0,1},
	{1,0,0,1,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1}
};

static void	dda_algorithm(t_rays *r)
{
	while (1)
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (testMap[r->map_x][r->map_y] == 1)
			break;
	}
}

static void	draw_ver_line(int x, t_cube *cube)
{
	uint32_t	color;
	t_rays		*r;
	int			line_h;
	int			y;
	int			pixel_start;
	int			pixel_end;

	color = 0x00FF0000;
	r = cube->rays;
	line_h = (int)(HEIGHT / r->perp_walldist);
	pixel_start = -line_h / 2 + HEIGHT / 2;
	if (pixel_start < 0)
		pixel_start = 0;
	pixel_end = line_h / 2 + HEIGHT / 2;
	if (r->side == 1)
		color = color / 2;
	y = pixel_start;
	while (y <= pixel_end)
	{
		mlx_put_pixel(cube->foreground, x, y, color);
		y++;
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
	r->map_x = p->pos_x;
	r->map_y = p->pos_y;
	while (x < 11)
	{
	//	printf("x = %d in raycasting()\n", x);
		r->camera_x = 2 * x / (double)WIDTH - 1;
		r->raydir_x = p->dir_x + p->plane_x * r->camera_x;
		r->raydir_y = p->dir_y + p->plane_y * r->camera_x;
		r->delta_distx = (r->raydir_x == 0) ? 1e30 : fabs(1 / r->raydir_x);
		r->delta_disty = (r->raydir_y == 0) ? 1e30 : fabs(1 / r->raydir_y);
		if (r->raydir_x < 0)
		{
			r->step_x = -1;
			r->side_distx = (p->pos_x - r->map_x) * r->delta_distx;
		}
		else
		{
			r->step_x = 1;
			r->side_distx = (r->map_x + 1.0 - p->pos_x) * r->delta_distx;
		}
		if (r->raydir_y < 0)
		{
			r->step_y = -1;
			r->side_disty = (p->pos_y - r->map_y) * r->delta_disty;
		}
		dda_algorithm(r);
		if (r->side == 0)
			r->perp_walldist = (r->side_distx - r->delta_distx);
		else
			r->perp_walldist = (r->side_disty - r->delta_disty);
		draw_ver_line(x, cube);
		x++;
	}
}
