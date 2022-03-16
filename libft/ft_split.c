/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:06:48 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/31 16:04:10 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		size ++;
		i ++;
	}
	return (size);
}

static int	ft_countchars(char const *s, char c)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i > 0)
				if (s[i - 1] != c)
					r ++;
		}
		i ++;
	}
	if (s[i] == 0 && s[i -1] != c && i > 0)
		r ++;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	split = (char **)ft_calloc(ft_countchars(s, c) + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			split[j] = (char *)ft_calloc(ft_wordlen(s + i, c) + 1,
					sizeof(char));
			if (!split[j])
				return (NULL);
			ft_strlcpy(split[j], s + i, ft_wordlen(s + i, c) + 1);
			i += ft_wordlen(s + i, c);
			j ++;
		}
	}
	return (split);
}
