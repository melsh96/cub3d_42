/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:35:51 by cchapon           #+#    #+#             */
/*   Updated: 2023/03/31 16:13:45 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, const char *s2)
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

int to_end(char *s)
{
    int i;

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