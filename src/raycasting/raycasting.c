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

void calculate_texture(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_x = data->player.pos_y + data->ray.perp_wall_dist * data->ray.ray_dir_y;
    else
		data->ray.wall_x = data->player.pos_x + data->ray.perp_wall_dist * data->ray.ray_dir_x;
    data->ray.wall_x -= floor((data->ray.wall_x));
	data->ray.tex_x = (int)(data->ray.wall_x * (double)(data->texture[data->NO].width));
	if ((data->ray.side == 0 && data->ray.tex_x > 0) || (data->ray.side == 1 && data->ray.ray_dir_y < 0)) 
		data->ray.tex_x = data->texture[data->NO].width - data->ray.tex_x - 1;
}

// void	which_texture(t_data *data, int *side)
// {
// 	if (data->ray.side == 0)
// 	{
// 		if (data->ray.ray_dir_x > 0)
// 			*side = data->NO;
// 		else
// 			*side = data->SO;
// 	}
// 	else
// 	{
// 		if (data->ray.ray_dir_y > 0)
// 			*side = data->WE;
// 		else
// 			*side = data->EA;
// 	}
// }


// int get_tex_color(t_tex *tex, t_pos *pos)
// {
// 	if (pos->x >= 0 && pos->x < tex->width
// 		&& pos->y >= 0 && pos->y < tex->height)
// 	{
// 		return (*(int*)(tex->ptr + (4 * tex->width * (int)pos->y) + (4 * (int)pos->x)));
// 	}
// 	return (0x0);
// }

// int get_texture_color (t_texture *tex, int x, int y)
// {
// 	return (*(int*)(tex->mlx_ad + (4 * tex->width * y) + (4 * x)));
// }


// int get_texture_pixel(t_texture *tex, int id, int x, int y)
// {
// 		return(*(int*)(tex->mlx_ad + (y * tex->line_length + x * tex->bits_per_pixel / 8)));
// }

void	draw_texture(t_data *data)
{
	int		i;
	char	*dst;
	int		color;
	//t_texture	*tex; tex = data->texture[wich_texture]
	// int	side_texture;

	i = data->ray.draw_start;
	data->ray.draw_end = WINDOW_HEIGHT - data->ray.draw_start;
	calculate_texture(data);
	data->ray.step = 1.0 * data->texture[data->NO].height / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - WINDOW_HEIGHT / 2 + data->ray.line_height / 2) * data->ray.step;
	// side_texture = 0;
	// which_texture(data, &side_texture);
	// data->ray.img = data->texture[data->NO].img;
	while (i < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (data->texture[data->NO].height - 1);
		data->ray.tex_pos += data->ray.step;
		color = (*(int *)data->img.addr + (data->ray.tex_y * data->img.line_len + data->ray.tex_x * (data->img.bpp / 8)));
		//color = (*(int *)data->texture[data->NO].mlx_ad + (data->ray.tex_y * data->texture[data->NO].line_length + data->ray.tex_x * (data->texture[data->NO].bits_per_pixel / 8)));
		dst = data->img.addr + (i * data->texture[data->NO].line_length + data->ray.x * (data->texture[data->NO].bits_per_pixel / 8));
		*(int *)dst = color;
		//printf("color : %d\n", color);
		i++;
	}
}

void	pass_to_3d(t_data *data)
{
	int		j;
	int		i;
	char	*dst;

	j = -1;
	data->ray.draw_end = WINDOW_HEIGHT - data->ray.draw_start;
	i = data->ray.draw_end;
	while (++j < data->ray.draw_start)
	{
		dst = data->img.addr + (j * data->img.line_len + data->ray.x * (data->img.bpp / 8));
		*(unsigned int*)dst = data->ceil;
	}
	if (j <= data->ray.draw_end)
		draw_texture(data);
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
