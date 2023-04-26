/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:59 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 17:48:47 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	file_extension(char *av, char *c)
{
	int	len;

	len = ft_strlen(av) - 1;
	if (len < 4)
		return (1);
	if (ft_strncmp(av + (len - 3), c, 5) != 0)
		return (1);
	return (0);
}

int	is_map_line(char *line, int *is_map)
{
	int	i;

	i = 0;
	if (line[0] == '1' || line[0] == '0')
	{
		*is_map = 1;
		return (1);
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

void	file_error(char *msg)
{
	printf("%s%sError:%s %s\n", RED, BOLD, NC, msg);
	exit(1);
}

int	check_fd(t_data *data, char *av)
{
	data->fd = open(av, __O_DIRECTORY);
	if (data->fd >= 0)
		return (close(data->fd), 1);
	data->fd = open(av, O_RDONLY);
	if (data->fd <= 0)
		file_error("Can't open file");
	return (0);
}

int	parse_files(t_data *data, char *av)
{
	char	*line;
	int		is_map;

	is_map = 0;
	if (file_extension(av, ".cub") == 1)
		file_error("Wrong file extension");
	if (check_fd(data, av) == 1)
		return (1);
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break ;
		if (is_map_line(line, &is_map) == 1)
			data->map.height++;
		else if (is_map == 1)
			data->map.height++;
		else
			is_map = 0;
		free(line);
	}
	close(data->fd);
	if (data->map.height <= 0)
		file_error("No map in file");
	return (1);
}
