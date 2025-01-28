/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   image.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/28 19:26:30 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/28 19:39:28 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_texture_t	*load_png_to_texture(char *path_png, t_cube *cube)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path_png);
	if (!texture)
		error_exit(NULL, NULL, cube);
	return (texture);
}
