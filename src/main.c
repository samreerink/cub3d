/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 15:36:00 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/23 18:23:49 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	testMap[6][11]=
{
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1}
};

int	main(void)
{
	t_cube	*cube;

	cube = init_cube();
	mlx_loop_hook(cube->mlx, cube_hook, cube);
	mlx_close_hook(cube->mlx, exit_cube, cube);
	mlx_key_hook(cube->mlx, key_input, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (EXIT_SUCCESS);
}
