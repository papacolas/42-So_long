/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:27:36 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/09 18:26:23 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	render(t_vars *vars)
{
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;
	char	cell_map;

	if (vars->end_game)
		return (0);
	i = 0;
	while (i < vars->map.height)
	{
		j = 0;
		while (j < vars->map.width)
		{
			pos_x = j * 32;
			pos_y = i * 32;
			cell_map = vars->map.grid[i][j];
			print_things(vars, pos_x, pos_y, cell_map);
			j++;
		}
		i++;
	}
	print_player_and_enemies(vars);
	return (0);
}

void	clean_before_exit(t_vars *vars)
{
	free_textures(vars);
	free_struct_map(&vars->map);
	if (vars->win_ptr && vars->mlx_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->mlx_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
	}
	get_next_line(-1);
	exit(0);
}

int	initialize_game(t_vars *vars, char *argv_one)
{
	int	window_width;
	int	window_height;

	struct_vars_init(vars);
	if (read_the_map(argv_one, &vars->map))
		return (1);
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
	{
		free_struct_map(&vars->map);
		return (1);
	}
	window_height = vars->map.height * 32;
	window_width = vars->map.width * 32;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, window_width,
			window_height, "So Long");
	if (!vars->win_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		return (1);
	}
	vars->player_x = vars->map.pos_x * 32;
	vars->player_y = vars->map.pos_y * 32;
	return (0);
}

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen2(filename);
	if (len < 5)
	{
		ft_putstr_fd("Error\nNom de fichier trop court\n", 2);
		return (1);
	}
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'b'
		|| filename[len - 2] != 'e'
		|| filename[len - 1] != 'r')
	{
		ft_putstr_fd("Error\nCe n'est pas un fichier .ber\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPas le nombre exact d'arguements\n", 2);
		return (1);
	}
	if (check_extension(argv[1]))
		return (1);
	if (initialize_game(&vars, argv[1]))
		return (1);
	if (load_textures(&vars))
	{
		clean_before_exit(&vars);
		return (1);
	}
	render(&vars);
	mlx_hook(vars.win_ptr, 2, 1L << 0, mouvements_with_key, &vars);
	mlx_hook(vars.win_ptr, 17, 1L << 17, close_with_souris, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
