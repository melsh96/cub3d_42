/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:07:16 by meshahrv          #+#    #+#             */
/*   Updated: 2023/04/03 13:30:46 by cchapon          ###   ########.fr       */
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

// struct s_gnl
// {
// 	char			*content;
// 	t_gnl			*next;
// };

// char	*get_next_line(int fd);
// void	read_to_stash(int fd, t_gnl **stash);
// void	stash_to_line(t_gnl *stash, char **line);
// t_gnl	*lstnew_gnl(void *content);
// void	lstadd_back_gnl(t_gnl **lst, t_gnl *new);
// void	ft_lstclear_gnl(t_gnl **lst, void (*del)(void *));
// int		check_new_line(t_gnl *stash);
// void	malloc_line(char **line, t_gnl *stash);
// void	new_line_exists(t_gnl	*to_clear);

void	get_one_line(char *line, char *buff);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *str);
int 	to_end(char *s);

#endif
