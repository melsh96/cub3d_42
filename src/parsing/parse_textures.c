/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/27 18:23:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures(char *line)
{
	int	i;
	int	v;
	int	j;

	i = 0;
	v = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0 || \
	ft_strncmp(line + i, "SO ", 3) == 0 || \
	ft_strncmp(line + i, "WE ", 3) == 0 || \
	ft_strncmp(line + i, "EA ", 3) == 0)
		return (2);
	else if (ft_strncmp(line + i, "F ", 2) == 0 || \
	ft_strncmp(line + i, "C ", 2) == 0)
	{
		j = -1;
		while (line[++j])
			if (line[j] == ',')
				v++;
		if (v != 2)
			return (-1);
		return (1);
	}
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
	char	**tab;
	int		i;
	int		v;

	i = 0;
	v = 0;
	tab = ft_split(texture->path, ' ');
	while (tab[i])
		i++;
	if (i > 2)
		return (free_double_tab(tab), 1);
	texture->id = ft_strdup(tab[0]);
	texture->ad = ft_strdup(tab[1]);
	texture->ad[ft_strlen(tab[1]) - 1] = '\0';
	if (check_textures(texture->path) == 2)
		if (file_extension(texture->ad, ".xpm") == 1)
			get_color_error(data, tab, "Wrong file extension");
	if (check_textures(texture->path) == -1)
		get_color_error(data, tab, "Extra commas");
	return (free_double_tab(tab), 0);
}

int	get_color_int(t_data *data, char *color_line)
{
	char	**clrs;
	int		clr;
	int		i;
	int		j;

	clrs = ft_split(color_line, ',');
	i = -1;
	while (clrs[++i])
	{
		j = 0;
		while (clrs[i][j])
		{
			if (!ft_isdigit(clrs[i][j]))
				get_color_error(data, clrs, "Bad color description");
			j++;
		}
		if (ft_atoi(clrs[i]) < 0 || ft_atoi(clrs[i]) > 255)
			get_color_error(data, clrs, "Bad color range");
	}
	if (i != 3)
		get_color_error(data, clrs, "Bad color description");
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
