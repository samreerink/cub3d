/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 15:36:00 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/04 19:55:42 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_cube	*cube;

	if (argc != 2)
		error_exit("Cub3D requires exactly one argument", NULL, NULL);
	cube = init_cube(argv[1]);
	draw_background(cube);
	mlx_loop_hook(cube->mlx, cube_hook, cube);
	mlx_loop_hook(cube->mlx, key_input, cube);
	mlx_close_hook(cube->mlx, exit_cube, cube);
//	mlx_key_hook(cube->mlx, key_input, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (EXIT_SUCCESS);
}
