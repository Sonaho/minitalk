/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:40:04 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/17 09:44:04 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_size;
	size_t	s_size;

	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	i = 0;
	j = d_size;
	if (dstsize == 0)
		return (s_size);
	if (d_size < (dstsize - 1))
	{
		while (src[i] && ((d_size + i) < (dstsize - 1)))
		{
			dst[j++] = src[i++];
		}
		dst[j] = '\0';
	}
	if (d_size >= dstsize)
		return (dstsize + s_size);
	return (d_size + s_size);
}
