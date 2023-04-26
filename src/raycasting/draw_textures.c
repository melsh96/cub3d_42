/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:36:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 12:43:31 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void calculate_texture(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_x = data->player.pos_y + data->ray.perp_wall_dist * data->ray.ray_dir_y;
    else
		data->ray.wall_x = data->player.pos_x + data->ray.perp_wall_dist * data->ray.ray_dir_x;
    data->ray.wall_x -= floor((data->ray.wall_x));
	data->ray.tex_x = (int)(data->ray.wall_x * (double)(data->texture[data->NO].width));
	if ((data->ray.side == 0 && data->ray.ray_dir_x > 0) || (data->ray.side == 1 && data->ray.ray_dir_y < 0)) 
		data->ray.tex_x = data->texture[data->NO].width - data->ray.tex_x - 1;
}

void	which_texture(t_data *data, int *side)
{
	if (data->ray.side == 0)
	{
		if (data->ray.ray_dir_x > 0)
			*side = data->SO;
		else
			*side = data->NO;
	}
	else
	{
		if (data->ray.ray_dir_y > 0)
			*side = data->EA;
		else
			*side = data->WE;
	}
}

int	get_textel_val(t_data *data, int *side)
{
	int				tex_i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				res;

	tex_i = data->ray.tex_y * data->texture[*side].line_length + data->ray.tex_x * (data->texture[data->NO].bits_per_pixel / 8);
	r = (unsigned char)(data->texture[*side].mlx_ad)[tex_i + 2];
	g = (unsigned char)(data->texture[*side].mlx_ad)[tex_i + 1];
	b = (unsigned char)(data->texture[*side].mlx_ad)[tex_i];

	res = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (res);
}

void	draw_texture(t_data *data)
{
	int		i;
	char	*dst;
	int		color;
	//t_texture	*tex; tex = data->texture[wich_texture]
	int	side_texture;

	i = data->ray.draw_start;
	data->ray.draw_end = WINDOW_HEIGHT - data->ray.draw_start;
	calculate_texture(data);
	data->ray.step = 1.0 * data->texture[data->NO].height / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - WINDOW_HEIGHT / 2 + data->ray.line_height / 2) * data->ray.step;
	// side_texture = 0;
	which_texture(data, &side_texture);
	// data->ray.img = data->texture[data->NO].img;
	while (i < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (data->texture[data->NO].height - 1);
		data->ray.tex_pos += data->ray.step;
		// color = (*(int *)data->img.addr + (data->ray.tex_y * data->img.line_len + data->ray.tex_x * (data->img.bpp / 8)));
		// color = (*(int *)data->texture[data->NO].mlx_ad + (data->ray.tex_y * data->texture[data->NO].line_length + data->ray.tex_x * (data->texture[data->NO].bits_per_pixel / 8)));
		color = get_textel_val(data, &side_texture);
		dst = data->img.addr + (i * data->img.line_len + data->ray.x * (data->img.bpp / 8));
		*(int *)dst = color;
		
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
