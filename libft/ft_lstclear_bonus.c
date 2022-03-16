/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:59:10 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/24 12:26:24 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l1;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l1 = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = l1;
	}
	lst = NULL;
}
