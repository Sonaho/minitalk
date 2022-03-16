/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:11:07 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 15:05:11 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tlst;

	tlst = (t_list *)malloc(sizeof(t_list));
	if (tlst == NULL)
		return (0);
	tlst->content = content;
	tlst->next = NULL;
	return (tlst);
}
