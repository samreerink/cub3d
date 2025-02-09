/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   draw_wall_line.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/09 15:04:07 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 17:12:52 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calculate_wall_height(t_draw_w_data *d, t_cube *cube)
{
	double	perp_walldist;

	perp_walldist = cube->rays->perp_walldist;
	d->line_h = (int)(HEIGHT / perp_walldist);
	d->pixel_start = -d->line_h / 2 + HEIGHT / 2;
	if (d->pixel_start < 0)
		d->pixel_start = 0;
	d->pixel_end = d->line_h / 2 + HEIGHT / 2;
	if (d->pixel_end >= HEIGHT)
		d->pixel_end = HEIGHT - 1;
}

static void	calculate_wall_hit(t_draw_w_data *d, t_cube *cube)
{
	t_player		*p;
	t_rays			*r;

	p = cube->player;
	r = cube->rays;
	if (r->side == 0)
	{
		if (r->raydir_x > 0)
			d->tex = cube->wall_e;
		else
			d->tex = cube->wall_w;
		d->wall_x = p->pos_x + r->perp_walldist * r->raydir_y;
	}
	else
	{
		if (r->raydir_y > 0)
			d->tex = cube->wall_s;
		else
			d->tex = cube->wall_n;
		d->wall_x = p->pos_y + r->perp_walldist * r->raydir_x;
	}
	d->wall_x -= floor((d->wall_x));
}

static void	calculate_texture_pos(t_draw_w_data *d, t_cube *cube)
{
	t_rays			*r;

	r = cube->rays;
	d->tex_x = (int)(d->wall_x * (double)(d->tex->width));
	if (r->side == 0 && r->raydir_x > 0)
		d->tex_x = d->tex->width - d->tex_x - 1;
	if (r->side == 1 && r->raydir_y < 0)
		d->tex_x = d->tex->width - d->tex_x - 1;
	d->step = 1.0 * d->tex->height / d->line_h;
	d->tex_pos = (d->pixel_start - HEIGHT / 2 + d->line_h / 2) * d->step;
}

void	draw_wall_line(int x, t_cube *cube)
{
	int				y;
	t_player		*p;
	t_rays			*r;
	t_draw_w_data	d;

	p = cube->player;
	r = cube->rays;
	calculate_wall_height(&d, cube);
	calculate_wall_hit(&d, cube);
	calculate_texture_pos(&d, cube);
	y = d.pixel_start;
	while (y < d.pixel_end)
	{
		d.tex_y = (int)d.tex_pos & (d.tex->height - 1);
		d.tex_pos += d.step;
		d.px_tex = (d.tex_y * d.tex->width + d.tex_x) * 4;
		d.px_img = (y * cube->foreground->width + x) * 4;
		px(cube->foreground, d.tex, d.px_img, d.px_tex);
		y++;
	}
}
