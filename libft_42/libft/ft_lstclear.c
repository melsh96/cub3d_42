/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:37:07 by meshahrv          #+#    #+#             */
/*   Updated: 2023/02/16 12:40:34 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "../includes_libft/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_clear;
	t_list	*next;

	to_clear = NULL;
	next = NULL;
	if (lst == NULL || del == NULL)
		return ;
	to_clear = *lst;
	while (to_clear != NULL)
	{
		next = to_clear->next;
		if (to_clear->content != NULL)
		{
			del(to_clear->content);
			to_clear->content = NULL;
		}
		free(to_clear);
		to_clear = next;
	}
	*lst = NULL;
}

// void	print_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("content : %s ->", (char *)(list->content));
// 		list = list->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new_node;
// 	char	*a;
// 	char	*b;

// 	a = ft_strdup("foo");
// 	b = ft_strdup("bar");
// 	head = ft_lstnew(a);
// 	new_node = ft_lstnew(b);
// 	ft_lstadd_back(&head, new_node);
// 	print_list(head);
// 	ft_lstclear(&head, &free);
// 	print_list(head);
// 	return (0);
// }
