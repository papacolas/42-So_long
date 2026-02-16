/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:33:03 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:18:46 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	draw_black_square(t_vars *vars)
{
	int	x;
	int	y;
	int	color;
	int	pos_x;
	int	pos_y;

	color = 0x000000;
	pos_x = 0;
	pos_y = 0;
	y = pos_y;
	while (y < pos_y + 32)
	{
		x = pos_x;
		while (x < pos_x + 32)
		{
			mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	display_count_window(vars);
}

void	display_count_window(t_vars *vars)
{
	char	*moves;

	moves = ft_itoa(vars->moves_count);
	if (!moves)
		return ;
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 10, 22, 0xFFF000, moves);
	free(moves);
}
