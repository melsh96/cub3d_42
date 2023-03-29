/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/29 16:33:15 by meshahrv         ###   ########.fr       */
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

int	parse_files(char *av)
{
	int		fd;
	int		read_line;
	char	buf[1];

	if (file_extension(av, ".cub") == 1)
	{
		parse_error("Wrong file extension");
		return (0);
	}
	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		printf("%s%sError:%s Can't open file\n", RED, BOLD, NC);
		return (0);
	}
	read_line = read(fd, buf, 1);
	if (read_line <= 0)
	{
		if (read_line == 0)
			printf("%s%sError:%s The file is empty\n", RED, BOLD, NC);
		else if (read_line < 0)
			printf("%s%sError:%s Wrong file\n", RED, BOLD, NC);
		return (0);
	}
	close(fd);
	return (1);
}

void	init_map(t_map *map)
{
	map->line = NULL;
	map->tab = NULL;
}

int	read_lines(char *map_path)
{
	int		fd;
	char	*line;
	int		count_lines;

	count_lines = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("%s%sError:%s Fail to open file\n", RED, BOLD, NC);
		exit(0);
	}
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
int	get_map(t_map *map, char *file)
{
	char	**map_path;

	map->height = read_lines(file);
	if (map->height == -1)
	{
		printf("%s%sError:%s Fail to read file\n", RED, BOLD, NC);
		return (0);
		// TODO: quit(map);
	}
	map_path = read_map(map, file);
	map->width = (int)ft_strlen((map_path)[0]) - 1;
	map->tab = map_path;
	print_map(map);
	return (1);
}

// ^Main Program
/*
- Init structure
- Check nbr or args
- Ckeck file
- Check map 
*/

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	init_map(&map);
	if (ac != 2)
		parse_error("Wrong number of arguments");
	if (!parse_files(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("%s%sError:%s Can't open file\n", RED, BOLD, NC);
		return (1);
	}
	if (!get_map(&map, av[1]))
		return (1);
	return (0);
}
