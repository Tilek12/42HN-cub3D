/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:50:13 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/10/18 20:48:40 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

// void	move_player(t_data *data, double move_x, double move_y)
// {
// 	t_map			*map;
// 	t_player		*player;
// 	t_point_double	new;
// 	char			tile_x;
// 	char			tile_y;

// 	map = &data->map;
// 	player = &data->player;
// 	new.x = player->pos.x + move_x;
// 	new.y = player->pos.y + move_y;
// 	if (new.y > player->pos.y)
// 		tile_y = map->map2d[(int)(new.y + PADDING)][(int)player->pos.x];
// 	else
// 		tile_y = map->map2d[(int)(new.y - PADDING)][(int)player->pos.x];
// 	if (new.x > player->pos.x)
// 		tile_x = map->map2d[(int)player->pos.y][(int)(new.x + PADDING)];
// 	else
// 		tile_x = map->map2d[(int)player->pos.y][(int)(new.x - PADDING)];
// 	if (tile_y == '0' || (tile_y == '2' && data->door.status == OPEN))
// 		player->pos.y = new.y;
// 	if (tile_x == '0' || (tile_x == '2' && data->door.status == OPEN))
// 		player->pos.x = new.x;
// }

void	move_player(t_data *data, double move_x, double move_y)
{
	t_map			*map;
	t_player		*player;
	t_point_double	new;
	char			tile_x;
	char			tile_y;

	map = &data->map;
	player = &data->player;
	new.x = player->pos.x + move_x;
	new.y = player->pos.y + move_y;
	if (new.y > player->pos.y)
		tile_y = map->map2d[(int)(new.y + PADDING)][(int)player->pos.x];
	else
		tile_y = map->map2d[(int)(new.y - PADDING)][(int)player->pos.x];
	if (new.x > player->pos.x)
		tile_x = map->map2d[(int)player->pos.y][(int)(new.x + PADDING)];
	else
		tile_x = map->map2d[(int)player->pos.y][(int)(new.x - PADDING)];
	if (tile_y == '0' || tile_y == 'O')
		player->pos.y = new.y;
	if (tile_x == '0' || tile_x == 'O')
		player->pos.x = new.x;
}

void	movement_mouse(t_data *data)
{
	double			*angle;
	t_point_int		pos;
	t_point_double	delta;

	angle = &data->player.angle;
	mlx_get_mouse_pos(data->mlx, &pos.x, &pos.y);
	delta.x = pos.x - (data->width / 2);
	*angle += delta.x * MOUSE_SPEED;
	if (*angle < 0)
		*angle += radian(360);
	else if (*angle > radian(360))
		*angle -= radian(360);
	mlx_set_mouse_pos(data->mlx, data->width / 2, data->height / 2);
}

void	movement_handler(t_data *data)
{
	double	*angle;

	angle = &data->player.angle;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(data, cos(*angle) * MOVE, sin(*angle) * MOVE);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(data, -cos(*angle) * MOVE, -sin(*angle) * MOVE);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(data, sin(*angle) * MOVE, -cos(*angle) * MOVE);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(data, -sin(*angle) * MOVE, cos(*angle) * MOVE);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		*angle -= ROTATE;
		if (*angle < 0)
			*angle += radian(360);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		*angle += ROTATE;
		if (*angle > radian(360))
			*angle -= radian(360);
	}
	movement_mouse(data);
}
