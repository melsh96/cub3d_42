/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:04:57 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/16 17:47:44 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/get_next_line_bonus.h"

t_gnl	*lstnew_gnl(void *content)
{
	t_gnl	*new_node;

	new_node = malloc(sizeof(t_gnl));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	lstadd_back_gnl(t_gnl **lst, t_gnl *new)
{
	t_gnl	*last_node;

	if (!lst || !new)
		return ;
	last_node = *lst;
	if (*lst != NULL)
	{	
		while (last_node->next != NULL)
			last_node = last_node->next;
	}
	if (last_node == NULL)
		*lst = new;
	else
		last_node->next = new;
}

void	new_line_exists(t_gnl	*to_clear)
{
	int		i;
	int		pos;

	i = 0;
	pos = check_new_line(to_clear) + 1;
	while (to_clear->content[i + pos] != '\0')
	{
		(to_clear->content)[i] = (to_clear->content)[i + pos];
		i++;
	}
	to_clear->content[i] = '\0';
}

int	check_new_line(t_gnl *node)
{
	int		i;
	t_gnl	*current;

	current = node;
	i = 0;
	if (current)
	{
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (i);
			i++;
		}
	}		
	return (-1);
}
