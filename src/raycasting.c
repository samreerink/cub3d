/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   raycasting.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/24 18:28:13 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/07 16:45:41 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
			break;
	}
}

static void	draw_wall_line(int x, t_cube *cube)
{
	t_player	*p;
	t_rays		*r;
	int			line_h;
	int			y;
	int			pixel_start;
	int			pixel_end;

	mlx_texture_t	*tex;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;

	p = cube->player;
	r = cube->rays;
	line_h = (int)(HEIGHT / r->perp_walldist);
	pixel_start = -line_h / 2 + HEIGHT / 2;
	if (pixel_start < 0)
		pixel_start = 0;
	pixel_end = line_h / 2 + HEIGHT / 2;
	if (pixel_end >= HEIGHT)
		pixel_end = HEIGHT - 1;
	// New >>>>
	// Wall texture selection
	if (r->side == 0)
	{
		if (r->raydir_x > 0)
			tex = cube->wall_e;
		else
			tex = cube->wall_w;
		wall_x = p->pos_x + r->perp_walldist * r->raydir_y;
	}
	else
	{
		if (r->raydir_y > 0)
			tex = cube->wall_s;
		else
			tex = cube->wall_n;
		wall_x = p->pos_y + r->perp_walldist * r->raydir_x;
	}
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(tex->width));
	if (r->side == 0 && r->raydir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / line_h;
	tex_pos = (pixel_start - HEIGHT / 2 + line_h / 2) * step;
	// New ^^^^
	y = pixel_start;
	while (y < pixel_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		uint32_t px_tex = (tex_y * tex->width + tex_x) * 4;
		uint32_t px_img = (y * cube->foreground->width + x) * 4;
		tex_px_to_px(cube->foreground, tex, px_img, px_tex);
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
	while (x < WIDTH)
	{
		r->map_y = (int)p->pos_y;
		r->map_x = (int)p->pos_x;
		r->camera_x = 2 * x / (double)WIDTH - 1;
		r->raydir_x = p->dir_x + p->plane_x * r->camera_x;
		r->raydir_y = p->dir_y + p->plane_y * r->camera_x;
		r->delta_distx = (r->raydir_x == 0) ? 1e30 : fabs(1 / r->raydir_x);
		r->delta_disty = (r->raydir_y == 0) ? 1e30 : fabs(1 / r->raydir_y);
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
		dda_algorithm(cube->map, r);
		if (r->side == 0)
			r->perp_walldist = (r->side_distx - r->delta_distx);
		else
			r->perp_walldist = (r->side_disty - r->delta_disty);
		draw_wall_line(x, cube);
		x++;
	}
}
