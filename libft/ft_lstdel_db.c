/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:45 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:46 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_db(t_lst_db **alst, void (*del)(void*, size_t))
{
	t_lst_db	*next_lst;
	t_lst_db	*tmp;

	if (alst)
	{
		next_lst = *alst;
		if ((*alst)->prev)
			((*alst)->prev)->next = NULL;
		while (next_lst != NULL)
		{
			if (del)
				del(next_lst->content, (*next_lst).content_size);
			tmp = next_lst->next;
			free(next_lst);
			next_lst = tmp;
		}
		*alst = NULL;
	}
}
