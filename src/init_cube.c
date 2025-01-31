/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   init_cube.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 14:59:41 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/31 19:59:13 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Temp function for map alloc
static void	init_map(t_cube *cube)
{
	int		file;
	char	*line;
	size_t	i;
	char	**map;

	i = 0;
	file = open("map.cub", O_RDONLY);
	if (file == -1)
		error_exit(NULL, "map.cub", cube);
	map = ft_calloc(7, sizeof(char *));
	if (!map)
		error_exit(NULL, "ft_calloc", cube);
	line = get_next_line(file);
	while (line)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(file);
		i++;
	}
	free(line);
	close(file);
	cube->map = map;
}

static void	init_player(t_cube *cube)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		error_exit(NULL, "ft_calloc", cube);
	player->pos_x = 1.50;
	player->pos_y = 4.50;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	cube->player = player;
}

static void	init_window_and_images(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!cube->mlx)
		error_exit(NULL, NULL, cube);
	cube->background = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->background)
		error_exit(NULL, NULL, cube);
	if (mlx_image_to_window(cube->mlx, cube->background, 0, 0) == -1)
		error_exit(NULL, NULL, cube);
	cube->foreground = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->foreground)
		error_exit(NULL, NULL, cube);
	if (mlx_image_to_window(cube->mlx, cube->foreground, 0, 0) == -1)
		error_exit(NULL, NULL, cube);
}

static void	load_assets(t_cube *cube)
{
	cube->wall_1 = load_png_to_texture("assets/Tile/Tile_02-128x128.png", cube);
	cube->wall_2 = load_png_to_texture("assets/Bricks/Bricks_11-128x128.png", cube);
}

t_cube	*init_cube(void)
{
	t_cube	*cube;

	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
		error_exit(NULL, "ft_calloc", NULL);
	init_map(cube);
	init_player(cube);
	cube->rays = ft_calloc(1, sizeof(t_rays));
	if (!cube->rays)
		error_exit(NULL, "ft_calloc", cube);
	init_window_and_images(cube);
	load_assets(cube);
	return (cube);
}
