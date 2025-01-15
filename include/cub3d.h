/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   cub3d.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/19 15:00:08 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/14 17:00:04 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include "../MLX42_animation/include/MLX42_animation.h"

typedef struct s_cube {
	mlx_t		*mlx;
	mlx_image_t	*foreground;
	t_sprite	*s;
	t_animation	*a;
} t_cube;

void	error_exit(char *msg, char *p_msg, t_cube *cube);
t_cube	*init_cube();
void	exit_cube(void *ptr);

#endif
