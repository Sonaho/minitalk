/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:36:02 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 15:53:04 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*t_tmp;

	t_tmp = lst;
	size = 0;
	while (t_tmp)
	{
		t_tmp = t_tmp->next;
		size ++;
	}
	return (size);
}
