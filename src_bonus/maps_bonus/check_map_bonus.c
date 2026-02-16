/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:32:04 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/08 15:19:01 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	extract_and_check_map_elements(t_map *map)
{
	extract_elements(map);
	if (check_elements(map))
		return (1);
	return (0);
}

//------------------------//
//		Walls			  //
//------------------------//
// Verifie la premiere et derniere ligne
// Verifie la premiere et la derniere colonne

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			ft_putstr_fd("Error\nLa carte n'est pas entouree de murs\n", 2);
			get_next_line(-1);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			ft_putstr_fd("Error\nLa carte n'est pas entouree de murs\n", 2);
			get_next_line(-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_accessibility(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = ft_duplicate_the_map(map);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nProbleme de malloc\n", 2);
		return (1);
	}
	floodfill(map_copy, map->pos_x, map->pos_y, map);
	i = 0;
	while (i < map->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (map->collectibles_acces != map->collectibles || map->exit_acces == 0)
	{
		ft_putstr_fd("Error\nLe chemin n'est pas valide\n", 2);
		get_next_line(-1);
		return (1);
	}
	return (0);
}

//------------------------//
//		check map		  //
//------------------------//

int	accept_or_not_the_map(t_map *map)
{
	if (extract_and_check_map_elements(map))
		return (1);
	if (check_walls(map))
		return (1);
	if (check_accessibility(map))
		return (1);
	return (0);
}
