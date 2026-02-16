/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:11:47 by ncrivell          #+#    #+#             */
/*   Updated: 2025/04/09 18:28:31 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	count_the_lines(int fd, t_map *map)
{
	char	*line;
	char	*backslash_n_to_backslash_0;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		backslash_n_to_backslash_0 = ft_strchr(line, '\n');
		if (backslash_n_to_backslash_0)
			*backslash_n_to_backslash_0 = '\0';
		if (ft_strlen2(line) != 0)
		{
			if (map->width == 0)
				map->width = ft_strlen2(line);
			if (is_rectangular(map, line, fd) == -1)
				return (-1);
			map->number_of_lines++;
		}
		free(line);
	}
	close(fd);
	return (map->number_of_lines);
}

int	open_map_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("Error\nImpossible d'ouvrir le fichier de la map\n", 2);
		return (1);
	}
	return (0);
}

int	stock_line_in_grid(t_map *map, char *filename)
{
	char	*backslash_n_to_backslash_0;
	char	*line;
	int		i;
	int		fd;

	if (open_map_file(filename, &fd))
		return (1);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		backslash_n_to_backslash_0 = ft_strchr(line, '\n');
		if (backslash_n_to_backslash_0)
			*backslash_n_to_backslash_0 = '\0';
		if (ft_strlen2(line) != 0)
			map->grid[i++] = line;
		else
			free(line);
	}
	map->grid[i] = NULL;
	close(fd);
	return (0);
}

int	infos_for_alloc_grid(char *filename, t_map *map)
{
	int	fd;
	int	count_lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nImpossible d'ouvrir le fichier de la map\n", 2);
		return (1);
	}
	count_lines = count_the_lines(fd, map);
	if (count_lines == 0)
	{
		ft_putstr_fd("Error\nLa carte est vide\n", 2);
		return (1);
	}
	if (count_lines == -1)
	{
		get_next_line(-1);
		return (1);
	}
	map->height = count_lines;
	return (0);
}

int	read_the_map(char *filename, t_map *map)
{
	if (infos_for_alloc_grid(filename, map))
		return (1);
	if (check_taille_map(map))
		return (1);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		ft_putstr_fd("Error\nProbleme d'allocation de memoire\n", 2);
		return (1);
	}
	if (stock_line_in_grid(map, filename))
	{
		free(map->grid);
		return (1);
	}
	if (accept_or_not_the_map(map))
	{
		free_struct_map(map);
		return (1);
	}
	return (0);
}
