/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:41:06 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/20 15:57:54 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = (unsigned int)ft_strlen(s);
	i = 0;
	ret = (char *)malloc(len +1);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = (*f)(i, s[i]);
		i ++;
	}
	ret[i] = 0;
	return (ret);
}
