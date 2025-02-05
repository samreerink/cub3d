/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   image.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/28 19:26:30 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/05 16:13:22 by sreerink      ########   odam.nl         */
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

void	tex_px_to_px(mlx_image_t *d, mlx_texture_t *s, uint32_t i_dst, uint32_t i_src)
{
	d->pixels[i_dst] = s->pixels[i_src];
	d->pixels[i_dst + 1] = s->pixels[i_src + 1];
	d->pixels[i_dst + 2] = s->pixels[i_src + 2];
	d->pixels[i_dst + 3] = s->pixels[i_src + 3];
}
