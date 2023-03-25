/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:04:13 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:57 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

// #include <stdio.h>

// void	print_node(t_list *new_node)
// {
// 	printf("content : %s\n", (char *)(new_node->content));
// 	printf("next : %p\n", (new_node->next));
// 	printf("new_node : %p\n", new_node);
// }

// int	main(void)
// {
// 	t_list	*new_node;
// 	char	*content;

// 	content = "blabla";
// 	new_node = ft_lstnew(content);
// 	print_node(new_node);
// 	return (0);
// }
