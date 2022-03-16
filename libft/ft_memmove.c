/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:33 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/18 14:25:52 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{	
		ft_memcpy(dst, src, n);
	}
	else
	{
		while (n--)
		{
			((char *)dst)[n] = ((char *)src)[n];
		}
	}
	return (dst);
}
