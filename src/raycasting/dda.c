/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:47:32 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 18:29:27 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* DDA Algorithm

	Loop that increments the ray with 1 square everytime, until a wall is hit.
	We can first check on coordinate x or coordinate y.

	side_dist x & y is incremented with delta_dist x or y 
	with the position of the player.
	
	When the ray has his a wall, the loop stops and we will know if we have 
	hit the wall x or y side based on the side (0 or 1);
*/
void	touch_wall(t_data **data)
{
	while ((*data)->ray.hit == 0)
	{
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
		if ((*data)->map.tab != NULL && \
			(*data)->map.tab[(*data)->ray.map_x][(*data)->ray.map_y] == '1')
			(*data)->ray.hit = 1;
	}
}

/* Calculate Distance Projected on Camera

	We calculate how hight is the distance of the ray before hitting the wall.
	
	We use the distance of the camera plane and 
	not the pos of the player to avoid fish eye effect.
	
	We check horizontally and vertically (side 0 or 1)
	the length of the ray projected

	Then we calculate the height of the line to draw on the screen :
	the screen size / ray distance before hiting the wall (wall height)

	Finally, the starting point of the wall and its end point before drawing
*/
void	find_wall(t_data **data)
{
	if ((*data)->ray.side == 0)
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_x - \
		(*data)->ray.ray_pos_x + (1 - (*data)->ray.step_x) / 2) / \
		(*data)->ray.ray_dir_x;
	else
		(*data)->ray.perp_wall_dist = ((*data)->ray.map_y - \
		(*data)->ray.ray_pos_y + (1 - (*data)->ray.step_y) / 2) / \
		(*data)->ray.ray_dir_y;
	(*data)->ray.line_height = (int)(WINDOW_HEIGHT / \
		(*data)->ray.perp_wall_dist);
	(*data)->ray.draw_start = -((*data)->ray.line_height) / 2 + \
		WINDOW_HEIGHT / 2;
	if ((*data)->ray.draw_start < 0)
		(*data)->ray.draw_start = 0;
	(*data)->ray.draw_end = (*data)->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if ((*data)->ray.draw_end >= WINDOW_HEIGHT)
		(*data)->ray.draw_end = WINDOW_HEIGHT - 1;
}
