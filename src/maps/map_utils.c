/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:04 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/14 16:11:03 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	floodfill(char **map_copy, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		map->collectibles_acces++;
	else if (map_copy[y][x] == 'E')
		map->exit_acces++;
	map_copy[y][x] = 'V';
	floodfill(map_copy, x + 1, y, map);
	floodfill(map_copy, x - 1, y, map);
	floodfill(map_copy, x, y + 1, map);
	floodfill(map_copy, x, y - 1, map);
}

char	**ft_duplicate_the_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_elements(t_map *map)
{
	if (map->collectibles < 1)
	{
		ft_putstr_fd("Error\nIl doit y avoir au moins un item\n", 2);
		get_next_line(-1);
		return (1);
	}
	if (map->exits != 1)
	{
		ft_putstr_fd("Error\nLa carte doit contenir exactement une sortie\n", 2);
		get_next_line(-1);
		return (1);
	}
	if (map->positions_start != 1)
	{
		ft_putstr_fd("Error\nQu'une seule position de depart\n", 2);
		get_next_line(-1);
		return (1);
	}
	if (map->error_letter != 0)
	{
		ft_putstr_fd("Error\nIl y a des caracteres invalides\n", 2);
		get_next_line(-1);
		return (1);
	}
	return (0);
}

int	check_taille_map(t_map *map)
{
	if (map->height > 37 || map->width > 60)
	{
		ft_putstr_fd("Error\nLa map est trop grande\n", 2);
		return (1);
	}
	return (0);
}

void	extract_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] == 'E')
				map->exits++;
			else if (map->grid[i][j] == 'P')
			{
				map->positions_start++;
				map->pos_x = j;
				map->pos_y = i;
			}
			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1')
				map->error_letter++;
			j++;
		}
		i++;
	}
}
