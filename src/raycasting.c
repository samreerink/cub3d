/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   raycasting.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/24 18:28:13 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/24 18:47:43 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	raycasting(t_player *p)
{
	int		x;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		raydir_x = p->dir_x + p->plane_x * camera_x;
		raydir_y = p->dir_y + p->plane_y * camera_x;
		x++;
	}
}
