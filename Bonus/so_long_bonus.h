/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:17:16 by ylabtaim          #+#    #+#             */
/*   Updated: 2022/02/19 17:15:48 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	char	**field;
	int		player;
	int		exit;
	int		collect;
	int		snake;
	int		p_x;
	int		p_y;
	int		height;
	int		width;
	int		img_height;
	int		img_width;
	int		steps;
	void	*texture_bird;
	void	*texture_grass;
	void	*texture_wall;
	void	*texture_worm;
	void	*texture_exit;
	void	*texture_snake;
	void	*texture_black;
	char	direction;
	int		count;
}	t_map;

void	valid_map(t_map *map, int fd, char *av);
void	game_init(t_map *map);
void	map_render(t_map *map, int i, int j);
int		key_hook(int key_code, t_map *map);
int		destroy_window(t_map *map);
int		bird_update(t_map *map);
void	fill_field(t_map *map, char *av, int fd, int i);
#endif