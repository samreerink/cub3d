/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_rgba.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/28 17:19:54 by sreerink      #+#    #+#                 */
/*   Updated: 2025/02/09 16:59:16 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
