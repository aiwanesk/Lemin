/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:42 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next_lst;
	t_list	*tmp;

	if (alst)
	{
		next_lst = *alst;
		while (next_lst != NULL)
		{
			if (del)
				(*del)(next_lst->content, (*next_lst).content_size);
			tmp = next_lst->next;
			free(next_lst);
			next_lst = tmp;
		}
		*alst = NULL;
	}
}
