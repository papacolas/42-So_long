/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:53:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:34:53 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

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
	ft_putstr_fd("GAME OVER :( !\n", 1);
	return (0);
}
