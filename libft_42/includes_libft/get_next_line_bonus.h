/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:07:16 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/16 17:58:11 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl	t_gnl;

struct s_gnl
{
	char			*content;
	t_gnl			*next;
};

char	*get_next_line(int fd);
void	read_to_stash(int fd, t_gnl **stash);
void	stash_to_line(t_gnl *stash, char **line);
t_gnl	*lstnew_gnl(void *content);
void	lstadd_back_gnl(t_gnl **lst, t_gnl *new);
void	ft_lstclear_gnl(t_gnl **lst, void (*del)(void *));
int		check_new_line(t_gnl *stash);
void	malloc_line(char **line, t_gnl *stash);
void	new_line_exists(t_gnl	*to_clear);

#endif
