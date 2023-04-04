/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:46:59 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/04 17:40:10 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_error(char *msg)
{
	printf("%s%sError:%s %s\n", RED, BOLD, NC, msg);
	exit(1);
}

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

// int is_map_line (char *line)
// {
// 	int	i;

// 	i = 0;
// 	if (line[0] == '1')
// 		return (1);
// 	while (line[i] == ' ')
// 		i++;
// 	if (line[i] == '1')
// 		return (1);
// 	return (0);
// }

int is_map_line (char *line, int *is_map)
{
	int	i;

	i = 0;
	if (line[0] == '1')
	{
		*is_map = 1;
		return (1);
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int	parse_files(t_data *data, char *av)
{
	char	*line;
	int		is_map;
	
	is_map = 0;
	if (file_extension(av, ".cub") == 1)
		parse_error("Wrong file extension");
	data->fd = open(av, __O_DIRECTORY);
	if (data->fd >= 0)
		return (close(data->fd), 1);
	data->fd = open(av, O_RDONLY);
	if (data->fd <= 0)
		parse_error("Can't open file\n");
	while (1)
	{
		line = get_next_line(data->fd);
		if (line == NULL)
			break;
		if (is_map_line(line, &is_map) == 1)
			data->map.height++;
		else if (is_map == 1)// && line[0] != '\n')
			data->map.height++;
		else
			is_map = 0;
		data->file_length++;
		free(line);
	}
	close(data->fd);
	printf("data->map.height : %d\n", data->map.height);
	printf("tdata->file_length : %d\n", data->file_length);
	return (1);
}

// int	parse_files(t_data *data, char *av)
// {
// 	char	*line;
	
// 	if (file_extension(av, ".cub") == 1)
// 		parse_error("Wrong file extension");
// 	data->fd = open(av, __O_DIRECTORY);
// 	if (data->fd >= 0)
// 		return (close(data->fd), 1);
// 	data->fd = open(av, O_RDONLY);
// 	if (data->fd <= 0)
// 		parse_error("Can't open file\n");
// 	while (1)
// 	{
// 		line = get_next_line(data->fd);
// 		if (line == NULL)
// 			break;
// 		if (is_map_line(line) == 1)
// 			data->map.height++;
// 		data->file_length++;
// 		free(line);
// 	}
// 	close(data->fd);
// 	printf("data->map.height : %d\n", data->map.height);
// 	printf("tdata->file_length : %d\n", data->file_length);
// 	return (1);
// }