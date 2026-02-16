/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:26:30 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:21:06 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void	handle_exit_img(t_vars *vars)
{
	static int	commu = 0;
	long		time_passed;

	if (commu == 0)
	{
		gettimeofday(&vars->exit_start, NULL);
		commu = 1;
	}
	gettimeofday(&vars->exit_timer, NULL);
	time_passed = (vars->exit_timer.tv_sec) * 1000000;
	time_passed = time_passed + vars->exit_timer.tv_usec;
	if (time_passed % 100000 < 20)
		altern_exit_img(vars);
}

void	altern_exit_img(t_vars *vars)
{
	vars->exit_blink = !vars->exit_blink;
	if (vars->textures.exit.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->textures.exit.img_ptr);
	if (vars->exit_blink)
		vars->textures.exit.img_ptr = mlx_xpm_file_to_image(
				vars->mlx_ptr, "textures/exit.xpm",
				&vars->textures.exit.width,
				&vars->textures.exit.height);
	else
		vars->textures.exit.img_ptr = mlx_xpm_file_to_image(
				vars->mlx_ptr, "textures/exit2.xpm",
				&vars->textures.exit.width,
				&vars->textures.exit.height);
	if (!vars->textures.exit.img_ptr)
		ft_putstr_fd("Error\nÉchec du rechargement de la sortie\n", 2);
	render(vars);
}
