/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:57:27 by meshahrv          #+#    #+#             */
/*   Updated: 2022/10/05 15:25:33 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_libft/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	dest_len = 0;
	src_len = ft_strlen(src);
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len == size)
		return (src_len + size);
	while (src[j] && (dest_len + j) < (size - 1))
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	if (dest_len + j < size)
		dst[dest_len + j] = '\0';
	return (src_len + dest_len);
}
