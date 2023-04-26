/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays_in_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:26:36 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 14:08:52 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*	Get DDA Ready: Datas
	
	perp_wall_dist = length of the ray (calculated later)
*/
void	ray_init(t_data *data)
{
	data->ray.perp_wall_dist = 0;
	data->ray.hit = 0;
	data->ray.map_x = (int)data->player.pos_x;
	data->ray.map_y = (int)data->player.pos_y;
	data->ray.rot_speed = 0.2;
	data->ray.move_speed = 0.075 * 1.8;
}

/*	Get DDA Ready: Pythagoras Formulas
	
	delta_dist_x and y are the distance the ray has to travel to go from 1 x_side to next x_side,
	or 1 y_side to next y_side
	2 triangles are formed (delta dist x & y)
	We use Pythagoras formulas : 
	We search for the square root by getting the sum of one side (length 1 = 1 pixel cell) and
	the other side (ray_dir_y / ray_dir_x) witch is the amount of units the ray goes into the direction y
	when taking 1 step in direction x;
*/
void	init_delta_dist(t_data **data)
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

/*	Get DDA Ready: Steps
	
	side_dist_x and y are the distance the ray has to travel from its start position to first x & y side.
	It will be incremented while taking steps.

	Depending on the ray direction :
	step_x and y = what direction to step in x or y-direction (negative or positive)

	hit = Check if there is a potential line of pixel that could be hit
	side = later check if we have hit a line of pixel (0 yes, 1 no)
*/
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
