/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:34 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/17 20:15:14 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

// int	key_press(int keycode, t_data *data)
// {
// }

// ! Conditionnal jump
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

void	touch_wall(t_data **data)
{
	// printf("%sHello%s\n", RED, NC);
	while ((*data)->ray.hit == 0)
	{
		// Jump to next map square, either in x-direction, or in y-direction
		if ((*data)->ray.side_dist_x < (*data)->ray.side_dist_y)
		{
			(*data)->ray.side_dist_x += (*data)->ray.delta_dist_x;
			(*data)->ray.map_x += (*data)->ray.step_x;
			(*data)->ray.side = 0;
		}
		else
		{
			(*data)->ray.side_dist_y += (*data)->ray.delta_dist_y;
			(*data)->ray.map_y += (*data)->ray.step_y;
			(*data)->ray.side = 1;
		}
		// Check if ray has hit a wall
		if ((*data)->map.tab[(*data)->ray.map_x][(*data)->ray.map_y] == '1')
			(*data)->ray.hit = 1;
	}
}

void	find_wall(t_data **data)
{
	touch_wall(data);
	// Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
	if ((*data)->ray.side == 0)
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_x - (*data)->ray.ray_pos_x
				+ (1 - (*data)->ray.step_x) / 2) / (*data)->ray.ray_dir_x;
	else
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_y - (*data)->ray.ray_pos_y
				+ (1 - (*data)->ray.step_y) / 2) / (*data)->ray.ray_dir_y;
    // Calculate height of line to draw on screen
	// Cubsize * Screen Size / Ray distance (ex : 320px * 160px)
	(*data)->ray.line_height = (int)(WINDOW_HEIGHT / (*data)->ray.perp_wall_dist);
	// dprintf()
    // Calculate lowest and highest pixel to fill in current stripe
	(*data)->ray.draw_start = -((*data)->ray.line_height) / 2 + WINDOW_HEIGHT / 2;
	if ((*data)->ray.draw_start < 0)
		(*data)->ray.draw_start = 0;
	(*data)->ray.draw_end = (*data)->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if ((*data)->ray.draw_end >= WINDOW_HEIGHT)
		(*data)->ray.draw_end = WINDOW_HEIGHT - 1;
}

void	draw_texture(t_data *data)
{
	// int	i;
	// int	i_tex;

	// i = data->ray.draw_start - 1;
	data->ray.draw_end = WINDOW_HEIGHT - data->ray.draw_start;
	// calculate_texture(data);
	// i_tex = 0;
	// which_texture(data, &i_tex);
	// while (++i <= data->ray.draw_end)
	// {
	// 	data->ray.tex_y = (int)data->ray.tex_pos & (data->ray.tex_height - 1);
	// 	data->ray.tex_pos += data->ray.step;
	// 	display_texture(data, i, data->ray.x, i_tex);
	// }
}

void	pass_to_3d(t_data *data)
{
	int		j;
	int		i;
	char	*dst;

	j = -1;
	data->ray.draw_end = WINDOW_HEIGHT - data->ray.draw_start;
	i = data->ray.draw_end;
	printf("end = %d\n", data->ray.draw_end);
	// printf("start = %d\n", data->ray.draw_start);
	while (++j < data->ray.draw_start)
	{
		dst = data->img.addr + (j * data->img.line_len + data->ray.x * (data->img.bpp / 8));
		*(unsigned int*)dst = data->ceil;
	}
	// if (j <= data->ray.draw_end)
	// 	draw_texture(data);
	j = i;
	while (++j < WINDOW_HEIGHT)
	{
		dst = data->img.addr + (j * data->img.line_len + data->ray.x * (data->img.bpp / 8));
		*(unsigned int*)dst = data->floor;
	}
}

void	draw(t_data *data)
{
	data->ray.x = -1;

	while (++data->ray.x < WINDOW_WIDTH)
	{
		ray_init(data);
		// Calculate ray position and direction
		data->ray.camera_x = 2 * data->ray.x / (double)WINDOW_WIDTH - 1; // x coordinate in camera space
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;
	
		// Length of ray from one x or y-side to next x or y-side
		init_rays(&data);

      	// Calculate step and initial sideDist
		init_step_side_distance(&data);

		data->ray.ray_pos_x = data->player.pos_x;
		data->ray.ray_pos_y = data->player.pos_y;

		data->ray.side = 0;

		// Start DDA Algo
		find_wall(&data);
		// printf("Hello\n");

		data->ray.hit = 0;
		
		// Calculate Texture
		pass_to_3d(data);
	}
	// return (0);
}

// int	key_press(int key_code, t_param *data)
// {
// 	if (key_code == KEY_W)d
// 		move_up(param);
// 	else if (key_code == KEY_A)
// 		move_left(param);
// 	else if (key_code == KEY_S)
// 		move_down(param);
// 	else if (key_code == KEY_D)
// 		move_right(param);
// 	return (0);
// }