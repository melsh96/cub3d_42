/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:54:25 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 18:34:07 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting_data(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	get_player_pos(data);
}

void	init_game_utils(t_data *data)
{
	data->ray.delta_dist_x = 0;
	data->ray.delta_dist_y = 0;
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.side = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.rotate_left = 0;
	data->ray.rotate_right = 0;
	data->ray.right = 0;
	data->ray.left = 0;
	data->ray.front = 0;
	data->ray.back = 0;
	data->ray.map_x = (int)data->player.pos_x;
	data->ray.map_y = (int)data->player.pos_y;
}

void	init_game(t_data *data)
{
	data->ray.rot_speed = 0;
	data->ray.move_speed = 0;
	data->ray.dir_x = 0;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0;
	data->ray.camera_x = 0;
	data->ray.ray_pos_x = 0;
	data->ray.ray_pos_y = 0;
	data->ray.old_dir_x = 0;
	data->ray.old_dir_y = 0;
	data->ray.old_plane_x = 0;
	data->ray.old_plane_y = 0;
	data->ray.ray_dir_x = 0;
	data->ray.ray_dir_y = 0;
	data->ray.map_x = 0;
	data->ray.map_y = 0;
	init_game_utils(data);
	init_direction(data);
}

void	init_direction(t_data *data)
{
	if (data->player.pos == 'N')
		data->ray.dir_x = -1;
	if (data->player.pos == 'S')
		data->ray.dir_x = 1;
	if (data->player.pos == 'E')
		data->ray.dir_y = 1;
	if (data->player.pos == 'W')
		data->ray.dir_y = -1;
	if (data->player.pos == 'N')
		data->ray.plane_y = 1;
	if (data->player.pos == 'S')
		data->ray.plane_y = -1;
	if (data->player.pos == 'E')
		data->ray.plane_x = 1;
	if (data->player.pos == 'W')
		data->ray.plane_x = -1;
}
