/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:25:00 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/14 16:08:30 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"

void	struct_map_init(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->positions_start = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->number_of_lines = 0;
	map->error_letter = 0;
	map->collectibles_acces = 0;
	map->exit_acces = 0;
}

void	struct_textures_init(t_textures *textures)
{
	textures->player.img_ptr = NULL;
	textures->player.width = 0;
	textures->player.height = 0;
	textures->wall.img_ptr = NULL;
	textures->wall.width = 0;
	textures->wall.height = 0;
	textures->floor.img_ptr = NULL;
	textures->floor.width = 0;
	textures->floor.height = 0;
	textures->collectibles.img_ptr = NULL;
	textures->collectibles.width = 0;
	textures->collectibles.height = 0;
	textures->exit.img_ptr = NULL;
	textures->exit.width = 0;
	textures->exit.height = 0;
}

void	struct_vars_init(t_vars *vars)
{
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->collected = 0;
	vars->victory = 0;
	vars->end_game = 0;
	vars->moves_count = 0;
	struct_map_init(&vars->map);
	struct_textures_init(&vars->textures);
}
