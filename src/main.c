/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:35 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/06 18:47:44 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	destroy_cub(t_data *data)
{
	free_double_tab(data->map.tab, (size_t)data->map.height);
	free_texture(data);
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
	parse_files(&data, av[1]);
	get_textures(&data, av[1]);
	get_map(&data);
	for (int i = 0; i < 6; i++)
		printf("i = %d : path = %s ; id = %s ; addr = %s\n", i, data.texture[i].path, data.texture[i].id, data.texture[i].addr);
	init_data(&data);
	return (0);
}
