/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:02:19 by cchapon           #+#    #+#             */
/*   Updated: 2023/03/31 12:36:10 by cchapon          ###   ########.fr       */
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
		fd = open(line + 3, O_RDONLY);
		if (fd < 0 || file_extension(line + 3, ".xpm") != 0)
		{
			printf("%s%sError ici :%s Wrong file\n", RED, BOLD, NC);
			return (-1);
		}
		close(fd);
	 //put mlx to image sur le path line + 3
	 // si ca plante, fre (line) return error
		dprintf(2, "line = %s", line + 3);
	}
	if (line[0] == 'F' || line[0] == 'C')
	{
		dprintf(2, "Get colors floor and ceiling\n");
	}
	else
		return (-1);
	return (0);
	// si caractere invlide : vider ligner + return error
	// int	i;

	// data->textures->count = 0;
	// i = 0;
}

void	get_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->texture.tab[i] = get_next_line(data->fd);
		// printf("tab %d : %s\n", i,  data->texture.tab[i]);
		if (!data->texture.tab[i])
		{
			// break;
			close(data->fd);
			return ;
		}
		// else
		// 	read_free_all_gnl(data->texture.tab[i], data->fd);
		// printf("tab %d : %s\n", i,  data->texture.tab[i]);
		// printf("tab [%i][0] : %c\n", i, data->texture.tab[i][0]);
		if (data->texture.tab[i][0] == '\n')
		{
			free(data->texture.tab[i]);
			// free_double_tab(data->texture.tab);
			i--;
		}
		else if (check_textures(data, data->texture.tab[i]) == -1)
		{
			// free_double_tab(data->texture.tab);
			close(data->fd);
			free(data->texture.tab[i]);
			parse_error("Wrong or missing id");
			//exit(1);
			// 
		}
		i++;
	}
	// close(data->fd);
	// free(data->texture.tab);
	// cas ou il manque une ligne de description ?
	print_map_texture(&data->texture);
}