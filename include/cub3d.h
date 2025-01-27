/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   cub3d.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/19 15:00:08 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/27 20:36:22 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include "../MLX42_animation/include/MLX42_animation.h"

# define WIDTH 1200
# define HEIGHT 800

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_rays
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_walldist;
}	t_rays;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*foreground;
	t_player	*player;
	t_rays		*rays;
}	t_cube;

void	error_exit(char *msg, char *p_msg, t_cube *cube);
t_cube	*init_cube(void);
void	cube_hook(void *ptr);
void	raycasting(t_cube *cube);
void	key_input(mlx_key_data_t keydata, void *ptr);
void	exit_cube(void *ptr);

#endif
