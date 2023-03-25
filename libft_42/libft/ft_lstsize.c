/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:10:42 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:24:16 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_nodes;

	n_nodes = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n_nodes++;
	}
	return (n_nodes);
}
