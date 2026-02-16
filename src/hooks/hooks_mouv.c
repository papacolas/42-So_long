/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:42:01 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/14 16:32:05 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

void	display_moves_count(t_vars *vars)
{
	write(1, "Nombre de coups joues = ", 24);
	ft_putnbr_fd(vars->moves_count, 1);
	write(1, "\r", 1);
}

int	handle_mouvements_keys(t_vars *vars, int keycode, int step)
{
	int	moved;

	moved = 0;
	if (keycode == 113 || keycode == 100 || keycode == 122 || keycode == 115)
	{
		moved = 1;
		vars->moves_count++;
	}
	if (keycode == 113) // q
		vars->player_x -= step;
	else if (keycode == 100) // d
		vars->player_x += step;
	else if (keycode == 122) // z
		vars->player_y -= step;
	else if (keycode == 115) // s
		vars->player_y += step;
	
	return (moved);
}

int	make_mouvement(t_vars *vars, int keycode, int step)
{
	int	save_x;
	int	save_y;

	save_x = vars->player_x;
	save_y = vars->player_y;
	if (!handle_mouvements_keys(vars, keycode, step))
		return (0);
	if (!check_collision_with_wall(vars, save_x, save_y, step))
		return (0);
	return (0);
}

int	mouvements_with_key(int keycode, t_vars *vars)
{
	int	step;
	int	temp_x;
	int	temp_y;

	if (!handle_esc_key(vars, keycode))
		return (0);
	if (vars->end_game)
		return (0);
	temp_x = vars->player_x / 32;
	temp_y = vars->player_y / 32;
	step = 32;
	if (make_mouvement(vars, keycode, step))
		return (0);
	display_moves_count(vars);
	update_map_after_mouvement(vars, temp_x, temp_y, step);
	if (!vars->end_game)
		render(vars);
	return (0);
}
