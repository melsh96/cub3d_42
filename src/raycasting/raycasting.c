/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:34 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/12 23:35:59 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	key_press(int keycode, t_data *data)
// {
// }

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
	data->ray.perp_wall_dist = 0;
	
    // Length of ray from current position to next x or y-side
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.hit = 0;
	
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
	// data->ray.map_x = data->player.pos_x;
	// data->ray.map_y = data->player.pos_y;
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

void	find_wall(t_data **data)
{
	touch_wall(data);
	if ((*data)->ray.side == 0)
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_x - (*data)->ray.ray_pos_x
				+ (1 - (*data)->ray.step_x) / 2) / (*data)->ray.ray_dir_x;
	else
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_y - (*data)->ray.ray_pos_y
				+ (1 - (*data)->ray.step_y) / 2) / (*data)->ray.ray_dir_y;
    // Calculate height of line to draw on screen
	(*data)->ray.line_height = (int)(HEIGHTSCREEN / (*data)->ray.perp_wall_dist);
    // Calculate lowest and highest pixel to fill in current stripe
	(*data)->ray.draw_start = -((*data)->ray.line_height) / 2 + HEIGHTSCREEN / 2;
	if ((*data)->ray.draw_start < 0)
		(*data)->ray.draw_start = 0;
	(*data)->ray.draw_end = (*data)->ray.line_height / 2 + HEIGHTSCREEN / 2;
	if ((*data)->ray.draw_end >= HEIGHTSCREEN)
		(*data)->ray.draw_end = HEIGHTSCREEN - 1;
}

void	pass_to_3d(t_data *data)
{
	int	j;
	int	i;

	j = -1;
	data->ray.draw_end = HEIGHTSCREEN - data->ray.draw_start;
	i = data->ray.draw_end;
	while (++j < data->ray.draw_start)
		data->ray.addr[j * data->ray.line_length / 4 + data->ray.x] = data->ray.ceiling_color;
	if (j <= data->ray.draw_end)
		// draw_texture(data->ray.
	j = i;
	while (++j < HEIGHTSCREEN)
		data->ray.addr[j * data->ray.line_length / 4 + data->ray.x] = data->ray.floor_color;
}

int	draw(t_data *data)
{
	data->ray.x = -1;
	while (++data->ray.x < WIDTHSCREEN)
	{
		// Calculate ray position and direction
		data->ray.camera_x = 2 * data->ray.x / (double)WIDTHSCREEN - 1; // x coordinate in camera space
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;
	
		// Which box of the map we're in
		data->ray.map_x = (int)data->player.pos_x;
		data->ray.map_y = (int)data->player.pos_y;

		// Used later to calculate the length of the ray
		data->ray.perp_wall_dist = 0;
		
		// Was there a wall hit?
		data->ray.hit = 0;

		// Speed modifiers
		data->ray.move_speed = 0.2;
		data->ray.rot_speed = 0.075 * 1.8;
		
		// Length of ray from one x or y-side to next x or y-side
		init_rays(&data);

      	// Calculate step and initial sideDist
		init_step_side_distance(&data);

		data->ray.ray_pos_x = data->player.pos_x;
		data->ray.ray_pos_y = data->player.pos_y;

		data->ray.side = 0;

		find_wall(&data);

		data->ray.hit = 0;

		pass_to_3d(data);
	}
}

int raycasting(t_data *data)
{
	init_raycasting_data(data);
	init_game(data);
	// mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, draw, data);
	printf("PLAYER POS_X = %f\n", data->player.pos_x);
	printf("PLAYER POS_Y = %f\n", data->player.pos_y);
	return (0);
}
