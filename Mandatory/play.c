/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:42:06 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/02/18 21:50:09 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_map *map)
{
	ft_free(map->field);
	mlx_destroy_window(map->mlx, map->mlx_win);
	printf("Closing the window!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	player_moves(t_map *map, int i, int j)
{
	if (map->field[map->p_x + i][map->p_y + j] != '1')
	{
		if (map->field[map->p_x + i][map->p_y + j] == 'C')
			map->collect--;
		else if (map->field[map->p_x + i][map->p_y + j] == 'E' \
				&& map->collect == 0)
		{
			ft_free(map->field);
			printf("You Win!\n");
			mlx_destroy_window(map->mlx, map->mlx_win);
			exit(EXIT_SUCCESS);
		}
		else if (map->field[map->p_x + i][map->p_y + j] == 'E' \
				&& map->collect != 0)
			return ;
		map->moves++;
		map->field[map->p_x + i][map->p_y + j] = 'P';
		map->field[map->p_x][map->p_y] = '0';
		map->p_x += i;
		map->p_y += j;
		printf("Moves: %d\n", map->moves);
		map_render(map, -1, -1);
	}
}

int	key_hook(int key_code, t_map *map)
{
	if (key_code == ESC)
		destroy_window(map);
	else if (key_code == A)
	{
		map->texture_bird = mlx_xpm_file_to_image(map->mlx, \
		"Mandatory/Xpms/bird_left.xpm", &map->img_width, &map->img_height);
		player_moves(map, 0, -1);
	}
	else if (key_code == W)
		player_moves(map, -1, 0);
	else if (key_code == D)
	{
		map->texture_bird = mlx_xpm_file_to_image(map->mlx, \
		"MAndatory/Xpms/bird_right.xpm", &map->img_width, &map->img_height);
		player_moves(map, 0, 1);
	}
	else if (key_code == S)
		player_moves(map, 1, 0);
	return (0);
}
