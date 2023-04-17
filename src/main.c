/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/17 13:10:47 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	destroy_cub(t_data *data)
{
	free_double_tab(data->map.tab, (size_t)data->map.height);
	free_texture(data);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	close (data->fd);
	free(data->mlx);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("%s%sError:%s Wrong argument number\n", RED, BOLD, NC);
		exit(1);
	}
	init_map(&data);
	if (parse_files(&data, av[1]))
	{
		get_textures(&data, av[1]);
		if (!get_map(&data))
		{
			free_double_tab(data.map.tab, (size_t)data.map.height);
			free_texture(&data);
			close(data.fd);
			exit(0);
		}
		else
		{
			printf("Let's Play !\n");
      		init_data(&data);
			// data.ray.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
			// data.ray.addr = (int *)mlx_get_data_addr(data.ray.img,
			// 	&data.ray.bits_per_pixel, &data.ray.line_length, &data.ray.endian);
			// raycasting(&data);
			// mlx_loop(data.mlx);
		}
	}
	// if (data.map.tab)
	//	free_double_tab_len(data.map.tab, (size_t)data.map.height);
	//free_params(data.texture.tab);
	//close (data.fd);
	return (0);
}
