/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:42:34 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/01/17 18:20:15 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_map *map, int i, int j, void *img_ptr)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	img_ptr, j * 48, i * 48);
}

void	show_moves(t_map *map)
{
	char	str[10];

	sprintf(str, "%d", map->steps);
	map->texture_black = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/just_black.xpm", &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->texture_black, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 2, 2, 0x625B03, "Moves: ");
	mlx_string_put(map->mlx, map->mlx_win, 70, 2, 0x625B03, str);
}

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->field[i][j] == '1')
				put_img(map, i, j, map->texture_wall);
			else
			{
				put_img(map, i, j, map->texture_grass);
				if (map->field[i][j] == 'P')
					put_img(map, i, j, map->texture_bird);
				else if (map->field[i][j] == 'C')
					put_img(map, i, j, map->texture_worm);
				else if (map->field[i][j] == 'E')
					put_img(map, i, j, map->texture_exit);
				else if (map->field[i][j] == 'S')
					put_img(map, i, j, map->texture_snake);
			}
		}
	}
	show_moves(map);
}

void	game_init(t_map *map)
{
	map->texture_bird = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/bird1.xpm", &map->img_width, &map->img_height);
	map->texture_snake = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/snake.xpm", &map->img_width, &map->img_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/bird_house.xpm", &map->img_width, &map->img_width);
	map->texture_grass = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/grass.xpm", &map->img_width, &map->img_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/wall.xpm", &map->img_width, &map->img_height);
	map->texture_worm = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/worm.xpm", &map->img_width, &map->img_height);
	if (!map->texture_bird || !map->texture_exit || !map->texture_grass \
		|| !map->texture_wall || !map->texture_worm || !map->texture_snake)
	{
		perror("Error with xpm files");
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
