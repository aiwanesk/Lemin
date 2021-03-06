/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttochar_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:39 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_lsttochar_db(t_lst_db **lst)
{
	char		*str;
	int			size;
	t_lst_db	*ptr;

	size = 0;
	ptr = *lst;
	while ((*lst) && (*lst)->next != NULL)
	{
		size = size + (*lst)->content_size;
		(*lst)->next->prev = *lst;
		*lst = (*lst)->next;
	}
	if ((*lst)->content == NULL || (*lst)->content_size == 0)
		*lst = (*lst)->prev;
	str = ft_strnew(size);
	while (str && (*lst) && (*lst)->content)
	{
		ft_strncat(str, (*lst)->content, (*lst)->content_size);
		*lst = (*lst)->prev;
	}
	*lst = ptr;
	return (str);
}
