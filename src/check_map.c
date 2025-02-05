/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   check_map.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/01 23:25:47 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/05 16:25:25 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_pos(size_t y, size_t x, t_player *p)
{
	p->pos_y = y + 0.50;
	p->pos_x = x + 0.50;
	// TO DO: Set direction values
}

static bool	check_line(char *line, size_t col, t_player *p)
{
	size_t	i;
	size_t	p_start_n;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (p->pos_y)
				return (false);
			set_player_pos(col, i, p);
		}
		else if (line[i] != '0' && line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

size_t	check_map(char *cub_file, t_cube *cube)
{
	int		file;
	char	*line;
	size_t	i;
	size_t	columns;

	file = open(cub_file, O_RDONLY);
	if (file == -1)
		error_exit(NULL, cub_file, cube);
	columns = 0;
	line = get_next_line(file);
	while (line)
	{
		if (!check_line(line, columns, cube->player))
		{
			free(line);
			error_exit("Invalid map", NULL, cube);
		}
		free(line);
		columns++;
		line = get_next_line(file);
	}
	close(file);
	return (columns);
}
