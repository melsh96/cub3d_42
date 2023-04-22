/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:45:27 by cchapon           #+#    #+#             */
/*   Updated: 2023/04/03 16:51:25 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		destroy_cub(data);
	return (0);
}

// int	key_press(int key_code, t_param *data)
// {
// 	if (key_code == KEY_W)d
// 		move_up(param);
// 	else if (key_code == KEY_A)
// 		move_left(param);
// 	else if (key_code == KEY_S)
// 		move_down(param);
// 	else if (key_code == KEY_D)
// 		move_right(param);
// 	return (0);
// }