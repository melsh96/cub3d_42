/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:04:57 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/03 13:29:05 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

// t_gnl	*lstnew_gnl(void *content)
// {
// 	t_gnl	*new_node;

// 	new_node = malloc(sizeof(t_gnl));
// 	if (new_node == NULL)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// void	lstadd_back_gnl(t_gnl **lst, t_gnl *new)
// {
// 	t_gnl	*last_node;

// 	if (!lst || !new)
// 		return ;
// 	last_node = *lst;
// 	if (*lst != NULL)
// 	{	
// 		while (last_node->next != NULL)
// 			last_node = last_node->next;
// 	}
// 	if (last_node == NULL)
// 		*lst = new;
// 	else
// 		last_node->next = new;
// }

// void	new_line_exists(t_gnl	*to_clear)
// {
// 	int		i;
// 	int		pos;

// 	i = 0;
// 	pos = check_new_line(to_clear) + 1;
// 	while (to_clear->content[i + pos] != '\0')
// 	{
// 		(to_clear->content)[i] = (to_clear->content)[i + pos];
// 		i++;
// 	}
// 	to_clear->content[i] = '\0';
// }

// int	check_new_line(t_gnl *node)
// {
// 	int		i;
// 	t_gnl	*current;

// 	current = node;
// 	i = 0;
// 	if (current)
// 	{
// 		while (current->content[i])
// 		{
// 			if (current->content[i] == '\n')
// 				return (i);
// 			i++;
// 		}
// 	}		
// 	return (-1);
// }

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup_gnl(const char *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(ft_strlen_gnl(s) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen_gnl(s))
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

size_t	ft_strlen_gnl(const char *str)
{
	int	l;

	l = 0;
	if (str == NULL)
		return (0);
	while (str[l])
		l++;
	return (l);
}

int	to_end(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}