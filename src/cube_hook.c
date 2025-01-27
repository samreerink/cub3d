/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   cube_hook.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 16:45:32 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/27 02:45:10 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cube_hook(void *ptr)
{
	t_cube		*cube;
//	mlx_image_t	*a_frame;

	cube = (t_cube *)ptr;
//	a_frame = get_frame_num(cube->a, cube->a->current_frame);
	clear_image(cube->foreground);
	raycasting(cube);
//	put_img(cube->foreground, a_frame, 200, 200);
//	update_animation(cube->a, cube->mlx->delta_time);
}
