/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:24:17 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/13 16:14:20 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_picture(t_data *data, t_picture *picture)
{
	//free(picture->addr);
	(void )data;
	if (picture->img)
	{
		printf("Yes\n");
		//mlx_destroy_image(data->mlx, picture->img);
	}
	free(picture);
}

void	free_texture(t_data *data)
{
	int s;

		s = -1;
	while (++s < 6 && data->texture[s].picture)
	{
		free_picture(data, data->texture[s].picture);
	}
	s = -1;
	while (++s < 6 && data->texture[s].path)
		free(data->texture[s].path);
	s = -1;
	while (++s < 6 && data->texture[s].id)
		free(data->texture[s].id);
	s = -1;
	while (++s < 6 && data->texture[s].addr)
		free(data->texture[s].addr);

}