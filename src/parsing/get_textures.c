/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/04 17:03:21 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void get_walls (char *line)
// {
	
// }

// void get_colors (char *line)
// {
	
// }

int	check_textures(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
	|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	else if (line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

// char 	*get_texture_param(char *line)
// {
// 	char	*addr;
// 	char	**tab;
// 	int		i;

// 	i = 0;
// 	tab = ft_split(line, ' ');
// 	addr = tab[1];
// 	free_double_tab(tab, i - 1);
// 	return (addr);
// }

void	get_texture_param(t_texture *texture)
{
	//int		i = 0;
	char	**tab;

	tab = ft_split(texture->path, ' ');
	texture->id = tab[0];
	texture->addr = tab[1];
	printf("tab 0 : %s\n", tab[0]);
	printf("id : %s\n", texture->id);
	// TODO probleme de free tab a regler.
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
			parse_error("Wrong or missing id");
		}
		else
		{
			//data->texture[i].addr = get_texture_param(data->texture[i].path);
			get_texture_param(&data->texture[i]);
			// dprintf(2, "id = %s\n", data->texture[i].id);
			// dprintf(2, "addr = %s\n", data->texture[i].addr);
		}
		i++;
	}
	//print_path(data->texture[i]->path, 6);
}