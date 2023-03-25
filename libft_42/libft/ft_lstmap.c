/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:52:29 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:23:49 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "../includes_libft/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*new_list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_element = ft_lstnew(f(lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

// void	print_list(t_list	*list)
// {
// 	while (list != NULL)
// 	{
// 		printf("[content : %s] -----> ", (char *)(list->content));
// 		list = list->next;
// 	}
// 	printf("NULL\n");
// }

// void	*change_first_letter(void *content)
// {
// 	char	*new_content;

// 	new_content = ft_strdup(content);
// 	if (new_content == NULL)
// 		return (NULL);
// 	new_content[0] = 'A';
// 	return ((void *) new_content);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*newhead;
// 	t_list	*new_node;
// 	char	*a;
// 	char	*b;

// 	a = ft_strdup("Hello");
// 	b = ft_strdup("Yellow");
// 	head = ft_lstnew(a);
// 	new_node = ft_lstnew(b);
// 	ft_lstadd_back(&head, new_node);
// 	print_list(head);
// 	newhead = ft_lstmap(head, &change_first_letter, &free);
// 	print_list(newhead);
// 	ft_lstclear(&newhead, &free);
// 	ft_lstclear(&head, &free);
// 	return (0);
// }
