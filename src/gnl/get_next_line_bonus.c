/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:03:03 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/03 13:29:49 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

// void	malloc_line(char **line, t_gnl *stash)
// {
// 	int	i;
// 	int	len;

// 	len = 0;
// 	while (stash != NULL)
// 	{
// 		i = 0;
// 		while (stash->content[i])
// 		{
// 			if (stash->content[i] == '\n')
// 			{
// 				len++;
// 				break ;
// 			}
// 			len++;
// 			i++;
// 		}
// 		stash = stash->next;
// 	}
// 	if (len == 0)
// 		*line = NULL;
// 	else
// 		*line = malloc(sizeof(char) * (len + 1));
// }

// // TODO	1 : read from fd & add to the stash
// void	read_to_stash(int fd, t_gnl **stash)
// {
// 	char			*buf;
// 	t_gnl			*new_node;
// 	int				line_read;

// 	new_node = *stash;
// 	line_read = 1;
// 	while (check_new_line(new_node) == -1 && line_read != 0)
// 	{
// 		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		if (buf == NULL)
// 			return ;
// 		line_read = read(fd, buf, BUFFER_SIZE);
// 		buf[line_read] = '\0';
// 		new_node = lstnew_gnl(buf);
// 		lstadd_back_gnl(stash, new_node);
// 	}
// }

// // TODO	2 : extract from stash to line till we reach a \n or end of file
// void	stash_to_line(t_gnl *stash, char **line)
// {
// 	int	i;
// 	int	j;

// 	if (stash == NULL)
// 		return ;
// 	malloc_line(line, stash);
// 	if (*line == NULL)
// 		return ;
// 	j = 0;
// 	while (stash)
// 	{
// 		i = 0;
// 		while (stash->content[i])
// 		{
// 			if (stash->content[i] == '\n')
// 			{
// 				(*line)[j++] = stash->content[i];
// 				break ;
// 			}
// 			(*line)[j++] = stash->content[i++];
// 		}
// 		stash = stash->next;
// 	}
// 	(*line)[j] = '\0';
// }

// // TODO	3 : clear the stash
// void	ft_lstclear_gnl(t_gnl **lst, void (*del)(void *))
// {
// 	t_gnl	*to_clear;
// 	t_gnl	*next;

// 	if (lst == NULL || del == NULL)
// 		return ;
// 	to_clear = *lst;
// 	while (to_clear != NULL)
// 	{
// 		next = to_clear->next;
// 		if (check_new_line(to_clear) == -1)
// 		{
// 			del(to_clear->content);
// 			free(to_clear);
// 		}
// 		else
// 		{
// 			new_line_exists(to_clear);
// 			break ;
// 		}
// 		to_clear = next;
// 	}
// 	*lst = to_clear;
// }

// char	*get_next_line(int fd)
// {
// 	char			*line;
// 	static t_gnl	*stash[FOPEN_MAX] = {NULL};

// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
// 		return (NULL);
// 	read_to_stash(fd, &stash[fd]);
// 	stash_to_line(stash[fd], &line);
// 	ft_lstclear_gnl(&stash[fd], free);
// 	return (line);
// }
void	get_one_line(char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (buff[j] && line[i + j])
	{
		buff[j] = line[i + j];
		j++;
	}		
	line[i] = '\0';
	buff[j] = '\0';
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[FOPEN_MAX][BUFFER_SIZE + 1];
	int				r;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	r = BUFFER_SIZE;
	line = NULL;
	line = ft_strjoin_gnl(line, buff[fd]);
	while (to_end(line) == 0 && r == BUFFER_SIZE)
	{
		r = read(fd, buff[fd], BUFFER_SIZE);
		if (r < 0)
			return (free(line), NULL);
		buff[fd][r] = '\0';
		line = ft_strjoin_gnl(line, buff[fd]);
	}
	if (line[0] == 0)
		return (free(line), NULL);
	get_one_line(line, buff[fd]);
	return (line);
}