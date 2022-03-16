/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:55:53 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 12:50:31 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_valstr(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	char	*r;
	int		remove;

	i = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		remove = 0;
		while (set[j])
		{	
			if (s1[i] == set[j])
				remove ++;
			j ++;
		}
		if (remove == 0)
			break ;
		i ++;
	}
	r = ft_substr(s1, i, ft_strlen(s1));
	return (r);
}

static char	*ft_valrstr(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		remove;
	char	*r;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		remove = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				remove ++;
			j ++;
		}
		if (remove == 0)
			break ;
		i --;
	}
	r = ft_substr(s1, 0, i + 1);
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	char	*f;
	size_t	size;

	size = ft_strlen(set);
	if (size > ft_strlen(s1))
	{
		r = (char *)malloc(size + 1);
		if (r == NULL)
			return (NULL);
		ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	}
	else
	{
		f = ft_valstr(s1, set);
		if (!f)
			return (NULL);
		r = ft_valrstr(f, set);
		if (!r)
			return (NULL);
		free(f);
	}
	return (r);
}
