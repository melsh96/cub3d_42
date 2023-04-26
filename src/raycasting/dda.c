/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:47:32 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 12:48:03 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		if ((*data)->map.tab != NULL && (*data)->map.tab[(*data)->ray.map_x][(*data)->ray.map_y] == '1')
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
