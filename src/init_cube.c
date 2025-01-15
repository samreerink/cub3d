/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   init_cube.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 14:59:41 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/15 15:08:48 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cube	*init_cube()
{
	t_cube	*cube;

	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
		error_exit(NULL, "ft_calloc", NULL);
	cube->mlx = mlx_init(1200, 800, "cub3d", false);
	if (!cube->mlx)
		error_exit(NULL, NULL, cube);
	cube->foreground = mlx_new_image(cube->mlx, 1200, 800);
	if (!cube->foreground)
		error_exit(NULL, NULL, cube);
	if (mlx_image_to_window(cube->mlx, cube->foreground, 0, 0) == -1)
		error_exit(NULL, NULL, cube);
	cube->s = load_sprite_sheet("./skeleton.png", 264, 264, cube->mlx);
	cube->a = init_animation(cube->s, 6, 6, 120);
	return (cube);
}
