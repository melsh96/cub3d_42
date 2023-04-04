/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:40 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/04 16:38:13 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <X11/keysym.h>
#include <../minilibx-linux/mlx.h>
# include "../libft_42/includes_libft/libft.h"
# include "get_next_line_bonus.h"

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
	char	*path;
	char	*id;
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_texture	texture[6];
	int			fd;
	int			file_length;
}	t_data;

// Main Program
int		main(int ac, char **av);
int		destroy_cub(t_data *data);

// Init
void	init_texture(t_data *data);
void	init_map(t_data *data);
void	init_data(t_data *data);

// Events
int	handle_input(int key, t_data *data);


// Parsing
int		file_extension(char *av, char *c);
int		parse_files(t_data *data, char *av);
void	parse_error(char *msg);
void	get_textures(t_data *data, char *av);

// Get Map
void	get_map(t_data *data);
int		read_lines(char *map_path, int fd);
char	**read_map(t_map *map, char *file);
int 	is_map_line (char *line);

// Utils
void	print_map(t_map *map);
void	read_free_all_gnl(char *tmp, int fd);
void	print_map_texture(t_texture *texture);
void	free_params(char **tab);
void	free_double_tab(char **tab, size_t len);
void	print_tab(char **tab, int tab_length);

#endif
