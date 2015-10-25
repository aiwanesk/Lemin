/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:28 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:29 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *nw)
{
	if (alst && nw)
	{
		nw->next = *alst;
		*alst = nw;
	}
}

void	ft_lstaddnew(t_list **alst, void *content, size_t size)
{
	t_list	*nw;

	nw = ft_lstnew(content, size);
	if (alst && *alst == NULL && nw)
		*alst = nw;
	else if (alst && nw)
	{
		nw->next = *alst;
		*alst = nw;
	}
}
