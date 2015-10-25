/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:36 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(void *content)
{
	t_list	*new_list;

	if ((new_list = (t_list*)ft_strnew(sizeof(t_list) - 1)) == NULL)
	{
		return (NULL);
	}
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

t_list	*ft_lstaddcreate(t_list **alst, void *content)
{
	t_list	*new_list;

	if ((new_list = ft_lstcreate(content)) == NULL)
		return (NULL);
	if (alst && *alst)
		new_list->next = *alst;
	*alst = new_list;
	return (*alst);
}
