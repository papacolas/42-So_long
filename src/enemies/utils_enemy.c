/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:53:30 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:21:44 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	is_valid_position(t_vars *vars, int x, int y)
{
	int		grid_x;
	int		grid_y;
	char	cell_map;

	grid_x = x / 32;
	grid_y = y / 32;
	if (grid_x < 0 || grid_y < 0 || grid_x >= vars->map.width
		|| grid_y >= vars->map.height)
		return (0);
	cell_map = vars->map.grid[grid_y][grid_x];
	if (cell_map == '1' || cell_map == 'C' || cell_map == 'E')
		return (0);
	return (1);
}
