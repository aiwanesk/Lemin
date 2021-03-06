/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:50 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelall_db(t_lst_db **alst)
{
	t_lst_db	*tmp;

	if (alst && *alst)
	{
		while ((*alst)->prev != NULL)
			*alst = (*alst)->prev;
		while ((*alst) != NULL)
		{
			tmp = (*alst)->next;
			bzero((*alst)->content, (*alst)->content_size);
			free((*alst)->content);
			(*alst)->prev = NULL;
			(*alst)->next = NULL;
			free((*alst));
			*alst = tmp;
		}
	}
}
