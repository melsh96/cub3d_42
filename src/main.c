/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/26 16:26:23 by cchapon          ###   ########.fr       */
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
			free_error_texture(&data);
			close(data.fd);
			exit(0);
		}
		else
		{
			printf("Let's Play !\n");
      		init_data(&data);
		}
	}
	return (0);
}
