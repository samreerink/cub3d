/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   cub3d.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/19 15:00:08 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/05 16:33:25 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include "../MLX42_animation/include/MLX42_animation.h"

# define WIDTH 1200
# define HEIGHT 800

typedef struct s_player
{
	double	pos_y;
	double	pos_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_rays
{
	int		map_y;
	int		map_x;
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
	mlx_t			*mlx;
	mlx_image_t		*foreground;
	mlx_image_t		*background;
	mlx_texture_t	*wall_1;
	mlx_texture_t	*wall_2;
	char			**map;
	t_player		*player;
	t_rays			*rays;
}	t_cube;

void			error_exit(char *msg, char *p_msg, t_cube *cube);
int				get_rgba(int r, int g, int b, int a);
mlx_texture_t	*load_png_to_texture(char *path_png, t_cube *cube);
void			tex_px_to_px(mlx_image_t *d, mlx_texture_t *s, uint32_t i_dst, uint32_t i_src);
t_cube			*init_cube(char *cub_file);
size_t			check_map(char *cub_file, t_cube *cube);
void			draw_background(t_cube *cube);
void			cube_hook(void *ptr);
void			raycasting(t_cube *cube);
void			key_input(void *ptr);
void			exit_cube(void *ptr);

#endif
