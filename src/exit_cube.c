/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   exit_cube.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/12/17 22:41:41 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/02 00:11:16 by sreerink      ########   odam.nl         */
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
	if (!cube)
		return ;
	free(cube->player);
	free_map(cube->map);
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
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	if (p_msg)
		perror(p_msg);
	if (mlx_errno)
	{
		mlx_msg = mlx_strerror(mlx_errno);
		write(STDERR_FILENO, mlx_msg, ft_strlen(mlx_msg));
		write(STDERR_FILENO, "\n", 1);
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
