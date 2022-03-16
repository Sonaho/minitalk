/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:23:03 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 11:05:46 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnum(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		num = num * -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	*ft_casezero(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = 48;
	ret[1] = 0;
	return (ret);
}

static void	ft_createstr(char *str, unsigned int num, int sign, int size)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		str[(size - 1) - i] = (num % 10) + 48;
		num /= 10;
		i ++;
	}
	if (sign)
	{
		str[0] = '-';
		str[i + 1] = 0;
	}	
	else
		str[i] = 0;
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		cnt;
	int		i;
	int		sign;

	sign = 0;
	i = 0;
	if (n == 0)
		ret = ft_casezero();
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		if (n < 0)
		{
			sign = 1;
			n *= -1;
		}
		cnt = ft_countnum(n) + sign;
		ret = (char *)malloc(cnt + 1);
		if (ret == NULL)
			return (NULL);
		ft_createstr(ret, (unsigned int)n, sign, cnt);
	}
	return (ret);
}
