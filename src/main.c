/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/26 17:52:18 by sreerink      #+#    #+#                 */
/*   Updated: 2024/11/26 21:19:48 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_image_t	*get_frame_num(t_animation *a, int cur_frame)
{
	t_frame	*temp;

	temp = a->frame;
	while (cur_frame > 0)
	{
		temp = temp->next;
		cur_frame--;
	}
	return (temp->img);
}

void	cube_hook(void *ptr)
{
	t_cube		*cube;
	mlx_image_t	*a_frame;

	cube = (t_cube *)ptr;
	a_frame = get_frame_num(cube->a, cube->a->current_frame);
	clear_image(cube->foreground);
	put_img(cube->foreground, a_frame, 200, 200);
	update_animation(cube->a, cube->mlx->delta_time);
}

int	main(void)
{
	t_cube	*cube;

	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
		return (1);
	cube->mlx = mlx_init(1200, 800, "cub3d", false);
	cube->foreground = mlx_new_image(cube->mlx, 1200, 800);
	mlx_image_to_window(cube->mlx, cube->foreground, 0, 0);
	cube->s = load_sprite_sheet("./skeleton.png", 264, 264, cube->mlx);
	cube->a = init_animation(cube->s, 6, 6, 120);
	mlx_loop_hook(cube->mlx, cube_hook, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	return (0);
}
