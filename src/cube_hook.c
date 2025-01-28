/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   cube_hook.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 16:45:32 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/28 00:21:15 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cube_hook(void *ptr)
{
	t_cube		*cube;

	cube = (t_cube *)ptr;
	clear_image(cube->foreground);
	raycasting(cube);
}
