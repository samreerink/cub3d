/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   exit_cube.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/12/17 22:41:41 by sreerink      #+#    #+#                 */
/*   Updated: 2025/01/28 00:43:17 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_cube(t_cube *cube)
{
	free_map(cube->map);
	free(cube->player);
	free(cube->rays);
	if (cube->mlx)
		mlx_terminate(cube->mlx);
	free(cube);
}

void	error_exit(char *msg, char *p_msg, t_cube *cube)
{
	const char	*mlx_msg;

	free_cube(cube);
	write(STDERR_FILENO, "Error\n", 6);
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	if (p_msg)
		perror(p_msg);
	if (mlx_errno)
	{
		mlx_msg = mlx_strerror(mlx_errno);
		write(STDERR_FILENO, mlx_msg, ft_strlen(mlx_msg));
	}
	exit(EXIT_FAILURE);
}

void	exit_cube(void *ptr)
{
	t_cube	*cube;

	cube = (t_cube *)ptr;
	if (cube)
		free_cube(cube);
	exit(EXIT_SUCCESS);
}
