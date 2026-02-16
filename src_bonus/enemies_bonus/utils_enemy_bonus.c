/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:53:30 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:21:18 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <time.h>

#define SPEED_BEGIN 12000
#define SPEED_EXIT 4000
#define ENEMIES_NBR 3

void	new_enemy_position(t_vars *vars, int id, int i, int j)
{
	vars->enemies[id].enemy_x = j * 32;
	vars->enemies[id].enemy_y = i * 32;
	vars->enemies[id].move = rand() % 4;
	vars->enemies[id].timer = 0;
}

void	positions_initiales_enemies(t_vars *vars)
{
	int	i;
	int	j;
	int	id;

	srand(time(NULL));
	id = 0;
	i = 0;
	while (i < vars->map.height && id < ENEMIES_NBR)
	{
		j = 0;
		while (j < vars->map.width && id < ENEMIES_NBR)
		{
			if (vars->map.grid[i][j] == '0' && (abs(j - vars->map.pos_x) > 2
			|| abs(i - vars->map.pos_y) > 2))
			{
				new_enemy_position(vars, id, i, j);
				id++;
				vars->enemy_squad++;
			}
			j++;
		}
		i++;
	}
}

int	init_enemies(t_vars *vars)
{
	vars->enemies = malloc(sizeof(t_enemy) * ENEMIES_NBR);
	if (!vars->enemies)
		return (1);
	positions_initiales_enemies(vars);
	return (0);
}

void	make_enemies_move(t_enemy *enemy)
{
	if (rand() % 10 == 0)
		enemy->move = rand() % 4;
	else if (enemy->move == 0)
		enemy->enemy_x += 32;
	else if (enemy->move == 1)
		enemy->enemy_y -= 32;
	else if (enemy->move == 2)
		enemy->enemy_x -= 32;
	else if (enemy->move == 3)
		enemy->enemy_y += 32;
}

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
