/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:42:34 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/02/19 17:07:14 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->field[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_wall, j * 48, i * 48);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_grass, j * 48, i * 48);
				if (map->field[i][j] == 'P')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_bird, j * 48, i * 48);
				else if (map->field[i][j] == 'C')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_worm, j * 48, i * 48);
				else if (map->field[i][j] == 'E')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_exit, j * 48, i * 48);
			}
		}
	}
}

void	game_init(t_map *map)
{
	map->texture_bird = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/bird_right.xpm", &map->img_width, &map->img_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/bird_house.xpm", &map->img_width, &map->img_width);
	map->texture_grass = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/grass.xpm", &map->img_width, &map->img_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/wall.xpm", &map->img_width, &map->img_height);
	map->texture_worm = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/worm.xpm", &map->img_width, &map->img_height);
	if (!map->texture_bird || !map->texture_exit || !map->texture_grass \
		|| !map->texture_wall || !map->texture_worm)
	{
		perror("Error with xpm files");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
