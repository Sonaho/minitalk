/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:18:15 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/17 09:43:40 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c)
{
	if (c == 32 || c == '\n' || c == '\f')
		return (1);
	else if (c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (isspace(*str))
		str++;
	while ((*str == 43 || *str == 45) && str)
	{
		if (*str == 45)
			sign *= -1;
		str ++;
		break ;
	}
	while (ft_isdigit(*str) && str)
	{
		num = (num * 10) + (*str - 48);
		str ++;
	}
	return (num * sign);
}
