/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:05:21 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 16:12:40 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"

int	load_people_textures(t_vars *vars)
{
	vars->textures.player.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/playerf1.xpm", &vars->textures.player.width,
			&vars->textures.player.height);
	if (!vars->textures.player.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image du joueur\n", 2);
		return (1);
	}
	vars->textures.enemy.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/bandit2.xpm", &vars->textures.enemy.width,
			&vars->textures.enemy.height);
	if (!vars->textures.enemy.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image de l'enemi\n", 2);
		return (1);
	}
	return (0);
}

int	load_floor_and_wall_textures(t_vars *vars)
{
	vars->textures.wall.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/wall.xpm", &vars->textures.wall.width,
			&vars->textures.wall.height);
	if (!vars->textures.wall.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image du mur\n", 2);
		return (1);
	}
	vars->textures.floor.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/floor.xpm", &vars->textures.floor.width,
			&vars->textures.floor.height);
	if (!vars->textures.floor.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image du sol\n", 2);
		return (1);
	}
	return (0);
}

int	load_exit_and_collectibles_textures(t_vars *vars)
{
	vars->textures.exit.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/exit.xpm", &vars->textures.exit.width,
			&vars->textures.exit.height);
	if (!vars->textures.exit.img_ptr || !vars->textures.exit.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image de la sortie\n", 2);
		return (1);
	}
	vars->textures.collectibles.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/collectible1.xpm", &vars->textures.collectibles.width,
			&vars->textures.collectibles.height);
	if (!vars->textures.collectibles.img_ptr)
	{
		ft_putstr_fd("Error\nImpossible de charger l'image du collectible\n", 2);
		return (1);
	}
	return (0);
}

int	load_textures(t_vars *vars)
{
	if (load_people_textures(vars))
		return (1);
	if (load_floor_and_wall_textures(vars))
		return (1);
	if (load_exit_and_collectibles_textures(vars))
		return (1);
	return (0);
}

void	free_textures(t_vars *vars)
{
	if (vars->textures.player.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.player.img_ptr);
	if (vars->textures.wall.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.wall.img_ptr);
	if (vars->textures.floor.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.floor.img_ptr);
	if (vars->textures.exit.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.exit.img_ptr);
	if (vars->textures.collectibles.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.collectibles.img_ptr);
	if (vars->textures.enemy.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.enemy.img_ptr);
}
