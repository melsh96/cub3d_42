/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:40 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/05 13:19:14 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <../minilibx-linux/mlx.h>
# include "../libft_42/includes_libft/libft.h"
# include "get_next_line_bonus.h"

# define NC		"\e[0m"
# define RED	"\e[31m"
# define BLUE	"\e[38;5;140m"
# define GREEN	"\e[38;5;150m"
# define BOLD	"\e[1m"

typedef struct s_count
{
	int	pos;
	int	pos_n;
	int	pos_s;
	int	pos_w;
	int	pos_e;
}	t_count;

typedef struct s_map
{
	char	*line;
	char	**tab;
	char	**final_map;
	int		width;
	int		height;
	int		longest_map_line;
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
	void		*mlx;
	t_map		map;
	t_texture	texture;
	int			fd;
	int			file_length;
	t_count		count;
}	t_data;

// Main Program
int		main(int ac, char **av);

// Init
void	init_map(t_data *data);

// Parsing
int		file_extension(char *av, char *c);
int		parse_files(t_data *data, char *av);
void	parse_error(char *msg);
void	get_textures(t_data *data, char *av);

// Get Map
// void	get_map(t_data *data);
int		get_map(t_data *data);
int		read_lines(char *map_path, int fd);
char	**read_map(t_map *map, char *file);
// int 	is_map_line (char *line);
int is_map_line (char *line, int *is_map);

// Utils
void	print_map(t_map *map);
void	read_free_all_gnl(char *tmp, int fd);
void	print_map_texture(t_texture *texture);
void	free_params(char **tab);
void	free_double_tab(char **tab, size_t len);
void	print_tab(char **tab, int tab_length);

void	free_double_tab_len(char **tab, size_t len);

#endif
