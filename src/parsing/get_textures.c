/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/05 17:31:22 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
	|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (1);
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

int	get_texture_param(t_texture *texture)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(texture->path, ' ');
	while (tab[i])
		i++;
	if (i > 2)
		return (free_double_tab(tab, i + 1), 1);
	texture->id = tab[0];
	texture->addr = tab[1];
	free_double_tab(tab, i + 1);
	return (0);
}

void	free_texture_path(int i, t_data *data)
{
	while (/*data->texture[i].path && */i > 0)
	{
		free(data->texture[i].path);
		printf("ok\n");
		i--;
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
		{
			close(data->fd);
			free(data->texture[i].path);
			free_texture_path(i, data);
			parse_error("Wrong or missing id");
		}
		else if (check_double_path(i, data, data->texture[i].path) == 1)
		{
			close(data->fd);
			free(data->texture[i].path);
			free_texture_path(i, data);
		 	parse_error("doublon");
		}
		else if (get_texture_param(&data->texture[i]) == 1)
		{
			close(data->fd);
			free(data->texture[i].path);
			free_texture_path(i, data);
			parse_error("trop d'espaces");
		}
		i++;
	printf("id : %s\n", data->texture[i].id);
	}
}