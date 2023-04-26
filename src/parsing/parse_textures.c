/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/26 18:25:56 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
	|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (2);
	else if (line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

int	check_double_path(int i, t_data *data, char *line)
{
	while (&data->texture[i -1] && i > 0)
	{
		if (ft_strncmp(data->texture[i - 1].path, line, ft_strlen(line)) == 0)
			return (1);
		i--;
	}
	return (0);
}

int	get_texture_param(t_data *data, t_texture *texture)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(texture->path, ' ');
	while (tab[i])
		i++;
	if (i > 2)
	{
		free_double_tab(tab);
		return (1);
	}
	texture->id = ft_strdup(tab[0]);
	texture->ad = ft_strdup(tab[1]);
	texture->ad[ft_strlen(tab[1]) - 1] = '\0';
	if (check_textures(texture->path) == 2 && \
	file_extension(texture->ad, ".xpm") == 1)
	{
		free_double_tab(tab);
		parse_error(data, "Wrong file extension !!");
	}
	free_double_tab(tab);
	return (0);
}

int	get_color_int(t_data *data, char *color_line)
{
	char	**clrs;
	int		i;
	int		l;
	int		clr;

	clrs = ft_split(color_line, ',');
	l = 0;
	while (clrs[l])
		l++;
	i = -1;
	while (clrs[++i])
	{
		if (l != 3 || ft_isalpha(clrs[i][0]))
		{
			free_double_tab(clrs);
			parse_error(data, "Bad color description");
		}
		if (ft_atoi(clrs[i]) < 0 || ft_atoi(clrs[i]) > 255)
		{
			free_double_tab(clrs);
			parse_error(data, "Bad color range");
		}
	}
	clr = ft_atoi(clrs[0]) << 16 | ft_atoi(clrs[1]) << 8 | ft_atoi(clrs[2]);
	return (free_double_tab(clrs), clr);
}

void	get_colors_and_range(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(data->texture[i].id, "F", 1) == 0)
		{
			data->F = i;
			data->floor = get_color_int(data, data->texture[i].ad);
		}	
		if (ft_strncmp(data->texture[i].id, "C", 1) == 0)
		{
			data->C = i;
			data->ceil = get_color_int(data, data->texture[i].ad);
		}
		if (ft_strncmp(data->texture[i].id, "NO", 2) == 0)
			data->NO = i;
		if (ft_strncmp(data->texture[i].id, "SO", 2) == 0)
			data->SO = i;
		if (ft_strncmp(data->texture[i].id, "WE", 2) == 0)
			data->WE = i;
		if (ft_strncmp(data->texture[i].id, "EA", 2) == 0)
			data->EA = i;
		i++;
	}
}
