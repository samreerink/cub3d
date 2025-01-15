/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 15:36:00 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/15 15:36:01 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cube_hook(void *ptr)
{
	t_cube		*cube;
	mlx_image_t	*a_frame;

	cube = (t_cube *)ptr;
	a_frame = get_frame_num(cube->a, cube->a->current_frame);
	clear_image(cube->foreground);
	put_img(cube->foreground, a_frame, 200, 200);
	update_animation(cube->a, cube->mlx->delta_time);
}

int	main(void)
{
	t_cube	*cube;

	cube = init_cube();
	mlx_loop_hook(cube->mlx, cube_hook, cube);
	mlx_close_hook(cube->mlx, exit_cube, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (EXIT_SUCCESS);
}
