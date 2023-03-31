/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/03/31 19:04:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void get_walls (char *line)
// {
	
// }

// void get_colors (char *line)
// {
	
// }

int	check_textures(t_data *data, char *line)
{
	(void)data;
	int		fd;
	
	fd = 0;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 \
	|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
	{
		dprintf(2, "line = %s", line + 3);
	}
	else if (line[0] == 'F' || line[0] == 'C')
	{
		dprintf(2, "Get colors floor and ceiling\n");
	}
	else
		return (-1);
	return (0);
}

void	get_textures(t_data *data, char *av)
{
	int	i;

	data->fd = open(av, O_RDONLY);
	i = 0;
	while (i < 6)
	{
		data->texture.tab[i] = get_next_line(data->fd);	
		if (!data->texture.tab[i])
		{
			// break;
			close(data->fd);
			return ;
		}
		if (data->texture.tab[i][0] == '\n')
		{
			free(data->texture.tab[i]);
			i--;
		}
		else if (check_textures(data, data->texture.tab[i]) == -1)
		{
			// free_double_tab(data->texture.tab);
			close(data->fd);
			free(data->texture.tab[i]);
			parse_error("Wrong or missing id");
		}
		i++;
	}
	print_map_texture(&data->texture);
}