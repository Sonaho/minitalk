/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:53:48 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/24 10:34:05 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t_tmp;

	if (!lst)
		return (NULL);
	t_tmp = lst;
	while (t_tmp->next)
		t_tmp = t_tmp->next;
	return (t_tmp);
}
