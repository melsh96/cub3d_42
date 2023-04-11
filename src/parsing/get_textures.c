/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/11 15:51:49 by cchapon          ###   ########.fr       */
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
	char **tab;

	i = 0;
	tab = ft_split(texture->path, ' ');
	while (tab[i])
		i++;
	if (i > 2)
	{
		free_double_tab(tab, i + 1);
		return (1);
	}
	texture->id = ft_strdup(tab[0]);
	texture->addr = ft_strdup(tab[1]);
	texture->addr[ft_strlen(tab[1]) -1] = '\0';
	if (check_textures(texture->path) == 2 && \
	file_extension(texture->addr, ".xpm") == 1)
	{
			free_double_tab(tab, i + 1);
			parse_error(data, "Wrong file extension !!");
	}
	free_double_tab(tab, i + 1);
	return (0);
}

int	get_color_int(t_data *data, char *color_line)
{
	char **colors;
	int	i;
	int	l;
	int color;

	colors = ft_split(color_line, ',');
	l = 0;
	while (colors[l])
		l++;
	if (l != 3)
	{
		free_double_tab(colors, l);
		parse_error(data, "Bad colors description");
	}
	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			free_double_tab(colors, l);
			parse_error(data, "Bad color range");
		}
		i++;
	}
	color = ft_atoi(colors[0]) << 16 | ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]);
	free_double_tab(colors, l);
	return (color);
}

void get_colors(t_data *data)
{
	int	i;
	int	len;
	
	i = 0;
	while (i < 6)
	{
		len = ft_strlen(data->texture[i].id);
		if (ft_strncmp(data->texture[i].id, "F", len) == 0)
			data->floor = get_color_int(data, data->texture[i].addr);
		if (ft_strncmp(data->texture[i].id, "C", len) == 0)
			data->ceil = get_color_int(data, data->texture[i].addr);
		i++;
	}
}

void	get_textures(t_data *data, char *av)
{
	int	i;

	data->fd = open(av, O_RDONLY);
	init_texture(data);
	i = 0;
	while (i < 6)
	{
		data->texture[i].path = get_next_line(data->fd);	
		if (!data->texture[i].path)
		{
			close(data->fd);
			return ;
		}
		if (ft_strncmp(data->texture[i].path, "\n", 1) == 0)
		{
			free(data->texture[i].path);
			i--;
		}
		else if (check_textures(data->texture[i].path) == 0)
			parse_error(data, "Wrong or missing id");
		else if (check_double_path(i, data, data->texture[i].path) == 1)
		 	parse_error(data, "doublon");
		else if (get_texture_param(data, &data->texture[i]) == 1)
			parse_error(data, "space en trop");
		i++;
	}
	get_colors(data);
	printf("floor : %d ; ceil : %d\n", data->floor, data->ceil);
}
