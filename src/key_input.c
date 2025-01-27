/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   key_input.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/23 17:09:06 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/27 20:41:18 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_input(mlx_key_data_t keydata, void *ptr)
{
	t_cube		*cube;

	cube = (t_cube *)ptr;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_cube(cube);
}
