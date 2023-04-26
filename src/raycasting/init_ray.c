/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:26:36 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 12:49:04 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting_data(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	get_player_pos(data);
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

void	ray_init(t_data *data)
{
	data->ray.perp_wall_dist = 0;
	data->ray.hit = 0;
	data->ray.map_x = (int)data->player.pos_x;
	data->ray.map_y = (int)data->player.pos_y;
	data->ray.rot_speed = 0.2;
	data->ray.move_speed = 0.075 * 1.8;
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
	data->ray.delta_dist_x = 0;
	data->ray.delta_dist_y = 0;
	// data->ray.perp_wall_dist = 0;
	
    // Length of ray from current position to next x or y-side
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	// data->ray.hit = 0;
	
	// Was a NS or a EW wall hit?
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
	init_direction(data);
}

void	init_rays(t_data **data)
{
	if ((*data)->ray.ray_dir_y == 0)
		(*data)->ray.delta_dist_x = 0;
	else if ((*data)->ray.ray_dir_x == 0)
		(*data)->ray.delta_dist_x = 1;
	else
		(*data)->ray.delta_dist_x = sqrt(1 + ((*data)->ray.ray_dir_y
					* (*data)->ray.ray_dir_y) / ((*data)->ray.ray_dir_x
					* (*data)->ray.ray_dir_x));
	if ((*data)->ray.ray_dir_x == 0)
		(*data)->ray.delta_dist_y = 0;
	else if ((*data)->ray.ray_dir_y == 0)
		(*data)->ray.delta_dist_y = 1;
	else
		(*data)->ray.delta_dist_y = sqrt(1 + ((*data)->ray.ray_dir_x
					* (*data)->ray.ray_dir_x) / ((*data)->ray.ray_dir_y
					* (*data)->ray.ray_dir_y));
}

void	init_step_side_distance(t_data **data)
{
	if ((*data)->ray.ray_dir_x < 0)
	{
		(*data)->ray.step_x = -1;
		(*data)->ray.side_dist_x = ((*data)->ray.ray_pos_x
				- (*data)->ray.map_x) * (*data)->ray.delta_dist_x;
	}
	else
	{
		(*data)->ray.step_x = 1;
		(*data)->ray.side_dist_x = ((*data)->ray.map_x + 1.0
				- (*data)->ray.ray_pos_x) * (*data)->ray.delta_dist_x;
	}
	if ((*data)->ray.ray_dir_y < 0)
	{
		(*data)->ray.step_y = -1;
		(*data)->ray.side_dist_y = ((*data)->ray.ray_pos_y
				- (*data)->ray.map_y) * (*data)->ray.delta_dist_y;
	}
	else
	{
		(*data)->ray.step_y = 1;
		(*data)->ray.side_dist_y = ((*data)->ray.map_y + 1.0
				- (*data)->ray.ray_pos_y) * (*data)->ray.delta_dist_y;
	}
}
