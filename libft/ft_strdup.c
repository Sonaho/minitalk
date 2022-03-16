/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:31:07 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/17 11:18:41 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen(s1);
	r = (void *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len && s1[i] != '\0')
		{
			r[i] = s1[i];
			i++;
		}
		r[len] = '\0';
	}
	return (r);
}
