/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:52 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:55 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		free(*alst);
		*alst = tmp;
	}
}
