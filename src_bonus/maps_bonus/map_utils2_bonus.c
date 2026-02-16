/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:45:07 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/09 18:46:39 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	is_rectangular(t_map *map, char *line, int fd)
{
	if (ft_strlen2(line) != map->width)
	{
		ft_putstr_fd("Error\nLa carte n'est pas rectangulaire!\n", 2);
		free(line);
		close(fd);
		return (-1);
	}
	return (0);
}

void	free_struct_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}
