/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:24:17 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/27 16:49:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_error_texture(t_data *data)
{
	int	s;

	s = -1;
	while (++s < 6 && data->texture[s].path)
		free(data->texture[s].path);
	s = -1;
	while (++s < 6 && data->texture[s].id)
		free(data->texture[s].id);
	s = -1;
	while (++s < 6 && data->texture[s].ad)
		free(data->texture[s].ad);
}

void	free_texture(t_data *data)
{
	int	s;

	s = -1;
	while (++s < 6)
	{
		if (data->texture[s].img)
			mlx_destroy_image(data->mlx, data->texture[s].img);
	}
	s = -1;
	while (++s < 6 && data->texture[s].path)
		free(data->texture[s].path);
	s = -1;
	while (++s < 6 && data->texture[s].id)
		free(data->texture[s].id);
	s = -1;
	while (++s < 6 && data->texture[s].ad)
		free(data->texture[s].ad);
}

void	parse_error(t_data *data, char *msg)
{
	close(data->fd);
	if (data->map.tab)
		free_double_tab(data->map.tab);
	free_error_texture(data);
	printf("%s%sError:%s %s\n", RED, BOLD, NC, msg);
	exit(1);
}

void	free_double_tab(char **tab)
{
	size_t	idx;

	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	if (tab)
		free(tab);
}

void	get_color_error(t_data *data, char**tab, char *msg)
{
	free_double_tab(tab);
	parse_error(data, msg);
}
