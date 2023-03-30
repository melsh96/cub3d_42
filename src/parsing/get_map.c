/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:44:28 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 15:50:45 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	read_lines(char *map_path, int fd)
{
	(void)map_path;
	char	*line;
	int		count_lines;

	count_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		
		count_lines++;
		free(line);
	}
	close(fd);
	free(line);
	return (count_lines);
}

char	**read_map(t_map *map, char *file)
{
	char	**map_path;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nFail to open file\n", 2);
		// TODO: quit(map);
	}
	map_path = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (map_path == NULL || fd == -1)
		exit (0);
	while (1)
	{
		map_path[i] = get_next_line(fd);
		if (map_path[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (map_path);
}

// TODO: Parse map file with NO/SO/WE/EA and /
int	get_map(t_data *data, char *file)
{
	data->map.height = read_lines(file, data->fd);
	if (data->map.height == -1)
	{
		printf("%s%sError:%s Fail to read file\n", RED, BOLD, NC);
		return (0);
		// TODO: quit(map);
	}
	data->map.tab = read_map(&data->map, file);
	data->map.width = (int)ft_strlen((data->map.tab)[0]) - 1;
	print_map(&data->map);
	return (1);
}
