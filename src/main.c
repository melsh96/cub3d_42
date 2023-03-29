/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/29 11:38:37 by meshahrv         ###   ########.fr       */
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

int	pars_files(char *av)
{
	int		fd;
	int		read_line;
	char	buf[1];

	if (file_extension(av, ".cub") == 1)
	{
		pars_error("Wrong file extension");
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

// TODO: Pars map file with NO/SO/WE/EA and /
// int pars_map(t_map *map, int fd)
// {
	
// }

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
		pars_error("Wrong number of arguments");
	if (!pars_files(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("%s%sError:%s Can't open file\n", RED, BOLD, NC);
		return (1);
	}
	// if (!pars_map(&map, fd))
	// {
	//     return (1);
	// }
	return (0);
}
