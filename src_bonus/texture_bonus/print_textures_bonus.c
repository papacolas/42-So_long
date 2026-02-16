/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:48:55 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:19:30 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	print_player_and_enemies(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->enemies && vars->textures.enemy.img_ptr)
	{
		while (i < vars->enemy_squad)
		{
			mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
				vars->textures.enemy.img_ptr,
				vars->enemies[i].enemy_x, vars->enemies[i].enemy_y);
			i++;
		}
	}
	i = 0;
	if (vars->textures.player.img_ptr)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->textures.player.img_ptr,
			vars->player_x, vars->player_y);
	}
}

void	print_things(t_vars *vars, int pos_x, int pos_y, char cell_map)
{
	if (cell_map == 'E' && vars->textures.exit.img_ptr)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->textures.exit.img_ptr, pos_x, pos_y);
	if (cell_map == 'C' && vars->textures.collectibles.img_ptr)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->textures.collectibles.img_ptr, pos_x, pos_y);
	if (cell_map == '0' && vars->textures.floor.img_ptr)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->textures.floor.img_ptr, pos_x, pos_y);
	if (cell_map == '1' && vars->textures.wall.img_ptr)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->textures.wall.img_ptr, pos_x, pos_y);
}
