/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:53:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/14 16:28:53 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define SPEED_BEGIN 12000
#define SPEED_EXIT 4000
#define ENEMIES_NBR 3

void	enemies_mouvements(t_vars *vars)
{
	int	id;
	int	temp_x;
	int	temp_y;

	id = 0;
	while (id < vars->enemy_squad)
	{
		vars->enemies[id].timer++;
		if (vars->enemies[id].timer == 30)
			vars->enemies[id].timer = 0;
		temp_x = vars->enemies[id].enemy_x;
		temp_y = vars->enemies[id].enemy_y;
		make_enemies_move(&vars->enemies[id]);
		if (!is_valid_position(vars, vars->enemies[id].enemy_x,
				vars->enemies[id].enemy_y))
		{
			vars->enemies[id].enemy_x = temp_x;
			vars->enemies[id].enemy_y = temp_y;
			vars->enemies[id].move = (vars->enemies[id].move + 1) % 4;
		}
		id++;
	}
}

int	check_attack(t_vars *vars)
{
	int	to_grid_player_x;
	int	to_grid_player_y;
	int	to_grid_bandit_x;
	int	to_grid_bandit_y;
	int	i;

	to_grid_player_x = vars->player_x / 32;
	to_grid_player_y = vars->player_y / 32;
	i = 0;
	while (i < vars->enemy_squad)
	{
		to_grid_bandit_x = vars->enemies[i].enemy_x / 32;
		to_grid_bandit_y = vars->enemies[i].enemy_y / 32;
		if (to_grid_player_x == to_grid_bandit_x
			&& to_grid_player_y == to_grid_bandit_y)
			return (1);
		i++;
	}
	return (0);
}

int	handle_player_defeat(t_vars *vars)
{
	int	color;
	int	text_x;
	int	text_y;

	color = 0xFFFFFF;
	text_x = (vars->map.width * 32) / 2 - 50;
	text_y = (vars->map.height * 32) / 2;
	vars->end_game = 1;
	render(vars);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->moves_count == 50)
	{
		mlx_string_put(vars->mlx_ptr, vars->win_ptr, text_x - 60,
			text_y + 60, color, "Limite de mouvements depassee!");
	}
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, text_x - 30, text_y + 30,
		0xFFFF00, "Appuyez sur ESC pour quitter");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, text_x, text_y, color,
		"PERDU..... LOOOOOOOSER !");
	display_moves_count(vars);
	ft_putstr_fd("\n======== GAME OVER :( ! ========\n", 1);
	return (0);
}

int	generate_enemies_mov(t_vars *vars)
{
	static int		frames = 0;
	int				speed;

	if (vars->end_game)
		return (0);
	speed = SPEED_BEGIN;
	if (vars->victory)
	{
		handle_exit_img(vars);
		speed = SPEED_EXIT;
	}
	frames++;
	if (frames % (speed) == 0)
	{
		enemies_mouvements(vars);
		if (check_attack(vars))
		{
			handle_player_defeat(vars);
			return (0);
		}
		render(vars);
	}
	return (0);
}
