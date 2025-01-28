/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   init_cube.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 14:59:41 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/28 01:23:03 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Temp function for map alloc
static char	**init_map(t_cube *cube)
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
	return (map);
}

static t_player	*init_player()
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = 6;
	player->pos_y = 3;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (player);
}

t_cube	*init_cube(void)
{
	t_cube	*cube;

	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
		error_exit(NULL, "ft_calloc", NULL);
	cube->map = init_map(cube);
	cube->player = init_player();
	if (!cube->player)
		error_exit(NULL, "ft_calloc", cube);
	cube->rays = ft_calloc(1, sizeof(t_rays));
	if (!cube->rays)
		error_exit(NULL, "ft_calloc", cube);
	cube->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!cube->mlx)
		error_exit(NULL, NULL, cube);
	cube->foreground = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->foreground)
		error_exit(NULL, NULL, cube);
	if (mlx_image_to_window(cube->mlx, cube->foreground, 0, 0) == -1)
		error_exit(NULL, NULL, cube);
	return (cube);
}
