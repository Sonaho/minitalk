/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:05 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 12:36:19 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		size1;
	int		size2;
	int		i;
	int		j;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	r = (char *)malloc(size1 + size2 +1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size2)
	{
		r[i + j] = s2[j];
		j ++;
	}
	r[i + j] = '\0';
	return (r);
}
