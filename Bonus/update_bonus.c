/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:43:55 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/01/17 18:21:39 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_img(t_map *map, char *file)
{
	map->texture_bird = mlx_xpm_file_to_image(map->mlx, \
	file, &map->img_width, &map->img_height);
}

void	bird_right_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/bird1.xpm");
	if (map->count >= 10)
		file_to_img(map, "Bonus/Xpms/bird2.xpm");
	if (map->count >= 20)
		file_to_img(map, "Bonus/Xpms/bird3.xpm");
	if (map->count >= 30)
		file_to_img(map, "Bonus/Xpms/bird4.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/bird5.xpm");
	if (map->count >= 50)
		file_to_img(map, "Bonus/Xpms/bird6.xpm");
	if (map->count >= 60)
		file_to_img(map, "Bonus/Xpms/bird7.xpm");
	if (map->count >= 70)
		file_to_img(map, "Bonus/Xpms/bird8.xpm");
	if (map->count >= 80)
		file_to_img(map, "Bonus/Xpms/bird9.xpm");
}

void	bird_left_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/bird_left1.xpm");
	if (map->count >= 10)
		file_to_img(map, "Bonus/Xpms/bird_left2.xpm");
	if (map->count >= 20)
		file_to_img(map, "Bonus/Xpms/bird_left3.xpm");
	if (map->count >= 30)
		file_to_img(map, "Bonus/Xpms/bird_left4.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/bird_left5.xpm");
	if (map->count >= 50)
		file_to_img(map, "Bonus/Xpms/bird_left6.xpm");
	if (map->count >= 60)
		file_to_img(map, "Bonus/Xpms/bird_left7.xpm");
	if (map->count >= 70)
		file_to_img(map, "Bonus/Xpms/bird_left8.xpm");
	if (map->count >= 80)
		file_to_img(map, "Bonus/Xpms/bird_left9.xpm");
}

int	bird_update(t_map *map)
{
	map->count++;
	if (map->count <= 90)
	{
		if (map->direction == 'R')
			bird_right_update(map);
		else
			bird_left_update(map);
	}
	else
		map->count = 0;
	map_render(map, -1, -1);
	return (0);
}
