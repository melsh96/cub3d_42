/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:40 by meshahrv          #+#    #+#             */
/*   Updated: 2023/03/30 17:33:07 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft_42/includes_libft/libft.h"
# include "../libft_42/includes_libft/get_next_line_bonus.h"

# define NC		"\e[0m"
# define RED	"\e[31m"
# define BLUE	"\e[38;5;140m"
# define GREEN	"\e[38;5;150m"
# define BOLD	"\e[1m"

typedef struct s_map
{
	char	*line;
	char	**tab;
	int		width;
	int		height;
}	t_map;

typedef struct s_texture
{
	char	*id;
	char	*line;
	char	*path;
	char	*tab[6];
	int		count;
}	t_texture;

typedef struct s_data
{
	t_map		map;
	t_texture	texture;
	int			fd;
}	t_data;

// Main Program
int		main(int ac, char **av);

// Init
void	init_map(t_data *data);

// Parsing
int		file_extension(char *av, char *c);
int		parse_files(t_data *data, char *av);
void	parse_error(char *msg);
void	get_textures(t_data *data);

// Get Map
int		get_map(t_data *data, char *file);
int		read_lines(char *map_path, int fd);
char	**read_map(t_map *map, char *file);

// Utils
void	print_map(t_map *map);

#endif
