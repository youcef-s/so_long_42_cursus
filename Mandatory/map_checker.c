/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:16:46 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/01/17 18:13:51 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_consistency(t_map *map)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map->field[++i])
	{
		j = -1;
		len = 0;
		while (map->field[i][++j] != '\n' && map->field[i][j])
			len++;
		if (len != map->width)
		{
			printf("Error\nInconsistent map!\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_walls(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->width)
	{
		if (map->field[0][x] != '1' || map->field[map->height - 1][x] != '1')
		{
			printf("Error\nThe walls are not placed properly!\n");
			exit(EXIT_FAILURE);
		}
	}
	x = -1;
	while (++x < map->height)
	{
		if (map->field[x][0] != '1' || map->field[x][map->width - 1] != '1')
		{
			printf("Error\nThe walls are not placed properly!\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	helper(t_map *map, int i, int j)
{
	if (map->field[i][j] != '0'
		&& map->field[i][j] != 'P'
		&& map->field[i][j] != '1'
		&& map->field[i][j] != 'C'
		&& map->field[i][j] != 'E')
	{
		printf("Error\nInvalid character in the map!\n");
		exit(EXIT_FAILURE);
	}
	if (map->field[i][j] == 'P')
	{
		map->player++;
		map->p_x = i;
		map->p_y = j;
	}
	else if (map->field[i][j] == 'E')
		map->exit++;
	else if (map->field[i][j] == 'C')
		map->collect++;
}

void	check_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			helper(map, i, j);
	}
	if (map->player != 1)
	{
		printf("Error\nNumber of players is inconvenient!\n");
		exit(EXIT_FAILURE);
	}
	if (map->exit == 0)
	{
		printf("Error\nThe exit is missing!\n");
		exit(EXIT_FAILURE);
	}
	if (map->collect == 0)
	{
		printf("Error\nNo collectables in the map!\n");
		exit(EXIT_FAILURE);
	}
}

void	valid_map(t_map *map, int fd, char *av)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		map->height++;
	if (close(fd) == -1)
	{
		perror("Error whhile closing the file");
		exit(EXIT_FAILURE);
	}
	map->field = (char **)malloc(sizeof(char *) * (map->height + 1));
	fd = open (av, O_RDONLY);
	while (i < map->height)
		map->field[i++] = get_next_line(fd);
	close (fd);
	i = 0;
	while (i < map->field[0][i])
		i++;
	map->width = i;
	map->field[map->height] = 0;
	check_consistency(map);
	check_walls(map);
	check_content(map);
}
