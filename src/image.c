/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   image.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/28 19:26:30 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 17:12:31 by sreerink      ########   odam.nl         */
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

void	px(mlx_image_t *d, mlx_texture_t *s, uint32_t di, uint32_t si)
{
	d->pixels[di] = s->pixels[si];
	d->pixels[di + 1] = s->pixels[si + 1];
	d->pixels[di + 2] = s->pixels[si + 2];
	d->pixels[di + 3] = s->pixels[si + 3];
}
