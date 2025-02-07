/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   draw_background.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/28 16:43:42 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/05 21:27:40 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_ceiling(int color, t_cube *cube)
{
	int	y;
	int	x;
	int	middle_screen;

	x = 0;
	middle_screen = HEIGHT / 2;
	while (x < WIDTH)
	{
		y = 0;
		while (y < middle_screen)
		{
			mlx_put_pixel(cube->background, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_floor(int color, t_cube *cube)
{
	int	y;
	int	x;
	int	middle_screen;

	x = 0;
	middle_screen = HEIGHT / 2;
	while (x < WIDTH)
	{
		y = middle_screen;
		while (y < HEIGHT)
		{
			mlx_put_pixel(cube->background, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_background(t_cube *cube)
{
	int	color1;
	int	color2;

	color1 = get_rgba(0, 0, 0, 255);
	color2 = get_rgba(47, 79, 79, 255);
	draw_ceiling(color1, cube);
	draw_floor(color1, cube);
}
