/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:41:55 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:49:04 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

int	check_collision_with_wall(t_vars *vars, int save_x, int save_y, int step)
{
	int	grid_x;
	int	grid_y;

	grid_x = vars->player_x / step;
	grid_y = vars->player_y / step;
	if (grid_x < 0 || grid_x >= vars->map.width || grid_y < 0
		|| grid_y >= vars->map.height
		|| vars->map.grid[grid_y][grid_x] == '1'
		|| (vars->map.grid[grid_y][grid_x] == 'E'
			&& vars->collected != vars->map.collectibles))
	{
		vars->player_x = save_x;
		vars->player_y = save_y;
		return (0);
	}
	return (1);
}

int	collision_with_collectible(t_vars *vars, int grid_x, int grid_y)
{
	vars->map.grid[grid_y][grid_x] = '0';
	vars->collected++;
	if (vars->collected == vars->map.collectibles)
	{
		vars->victory = 1;
	}
	return (0);
}

void	update_map_after_mouvement(t_vars *vars, int temp_x,
	int temp_y, int step)
{
	int	grid_x;
	int	grid_y;

	grid_x = vars->player_x / step;
	grid_y = vars->player_y / step;
	if (vars->map.grid[temp_y][temp_x] == 'P')
		vars->map.grid[temp_y][temp_x] = '0';
	if (vars->map.grid[grid_y][grid_x] == 'C')
		collision_with_collectible(vars, grid_x, grid_y);
	if (vars->map.grid[grid_y][grid_x] == 'E'
		&& vars->collected == vars->map.collectibles)
		handle_page_victory(vars, grid_x, grid_y);
	vars->map.grid[grid_y][grid_x] = 'P';
}
