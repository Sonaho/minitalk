/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:43:36 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/17 09:44:52 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
	{	
		if (ft_isupper(c))
			return (c + 32);
		return (c);
	}
	else
		return (c);
}
