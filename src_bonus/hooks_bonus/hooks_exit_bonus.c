/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:38:39 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/14 15:56:03 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

int	close_with_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		clean_before_exit(vars);
	return (0);
}

int	close_with_souris(t_vars *vars)
{
	clean_before_exit(vars);
	return (0);
}

int	handle_esc_key(t_vars *vars, int keycode)
{
	if (keycode == 65307)
	{
		clean_before_exit(vars);
		return (0);
	}
	if (vars->end_game)
	{
		if (keycode == 65307)
			clean_before_exit(vars);
		return (0);
	}
	return (1);
}

int	handle_page_victory(t_vars *vars, int grid_x, int grid_y)
{
	int	color;
	int	text_x;
	int	text_y;

	color = 0xFFFFFF;
	text_x = (vars->map.width * 32) / 2 - 50;
	text_y = (vars->map.height * 32) / 2;
	render(vars);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, text_x - 30, text_y + 30,
		0xFFFF00, "Appuyez sur ESC pour quitter");
	vars->end_game = 1;
	vars->map.grid[grid_y][grid_x] = 'P';
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, text_x, text_y, color,
		"VICTOIRE !");
	ft_putstr_fd("\n========= VICTOIRE !!!! ========\n", 1);
	return (0);
}

void	change_map_before_victory(t_vars *vars)
{
	if (vars->textures.exit.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.exit.img_ptr);
	vars->textures.exit.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/exit2.xpm", &vars->textures.exit.width,
			&vars->textures.exit.height);
	if (!vars->textures.exit.img_ptr)
		ft_putstr_fd("Erreur : Impossible de charger l'image exit\n", 2);
	if (vars->textures.floor.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.floor.img_ptr);
	vars->textures.floor.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/floor2.xpm", &vars->textures.floor.width,
			&vars->textures.floor.height);
	if (!vars->textures.floor.img_ptr)
		ft_putstr_fd("Erreur : Impossible de charger l'image du sol\n", 2);
	if (vars->textures.wall.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.wall.img_ptr);
	vars->textures.wall.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/wall2.xpm", &vars->textures.wall.width,
			&vars->textures.wall.height);
	if (!vars->textures.wall.img_ptr)
		ft_putstr_fd("Erreur : Impossible de charger l'image du mur\n", 2);
}
