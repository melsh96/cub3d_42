/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:40 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/17 19:58:00 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <../minilibx-linux/mlx.h>
# include "../libft_42/includes_libft/libft.h"
# include "get_next_line_bonus.h"
# include "math.h"

# define NC		"\e[0m"
# define RED	"\e[31m"
# define BLUE	"\e[38;5;140m"
# define GREEN	"\e[38;5;150m"
# define BOLD	"\e[1m"


#define WINDOW_WIDTH 1900
#define WINDOW_HEIGHT 800

#define BACKGROUND_COLOR 0xFFFFFF

typedef struct s_count
{
	int	pos;
	int	pos_n;
	int	pos_s;
	int	pos_w;
	int	pos_e;
}	t_count;

typedef struct s_player
{
	char	pos;
	double	pos_x;
	double	pos_y;
	int		right;
	int		left;
	int		front;
	int		back;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_ray
{
	int		x;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	dir_x;
	double	dir_y;
	double	old_dir_x;
	double	old_dir_y;
	double	plane_x;
	double	plane_y;
	double	old_plane_x;
	double	old_plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_pos_x;
	double	ray_pos_y;
	double	rot_speed;
	double	move_speed;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	step;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		rotate_right;
	int		rotate_left;
	int		left;
	int		right;
	int		front;
	int		back;
	
	int		*addr;
	void	*img;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	int		floor_color;
	int		ceiling_color;
	int		color1;
	int		color2;
	int		color3;
	int		color4;
	int 	tex_x;
	int		tex_y;
	double  tex_pos;
}	t_ray;

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
	char		*path;
	char		*id;
	char		*ad;
	void		*img;
	void		*mlx_ad;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	x;
	int	y;
	int width;
	int height;
}	t_texture;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_ray		ray;
	t_image		img;
	t_map		map;
	t_texture	texture[6];
	t_player	player;
	int			fd;
	int			file_length;
	t_count		count;
	unsigned int		floor;
	unsigned int		ceil;
	int				F;
	int				C;
	int				NO;
	int				SO;
	int				WE;
	int				EA;
}	t_data;

// Main Program
int		main(int ac, char **av);
int		destroy_cub(t_data *data);
void 	free_texture_tab(t_data *data);

// Init
void	init_texture(t_data *data);
void	init_map(t_data *data);
void	init_data(t_data *data);

// Events
int	handle_input(int key, t_data *data);

// Parsing
int		file_extension(char *av, char *c);
int		parse_files(t_data *data, char *av);
void	parse_error(t_data *data, char *msg);
void	get_textures(t_data *data, char *av);
void	get_textures_path(t_data *data, char *av);
void	free_texture(t_data *data);

// load descritpion
void	load_colors(t_data *data);
void	init_picture_data(t_data *data);
int		load_image (t_data *data);
int		render_colors(t_data *data);

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
void	print_texture(t_data *data);

void	free_double_tab_len(char **tab, size_t len);

// Raycasting
void 	raycasting(t_data *data);
void	get_player_pos(t_data *data);
void	init_raycasting_data(t_data *data);
void	init_game(t_data *data);
void	draw(t_data *data);
void	ray_init(t_data *data);
// void	init_direction(t_data *data);

#endif
