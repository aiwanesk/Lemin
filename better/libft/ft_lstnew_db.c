/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:41 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:43 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstnew_db(void const *cont, size_t cont_size)
{
	t_lst_db	*new;
	t_lst_db	*ptr;

	if ((new = (t_lst_db*)ft_strnew(sizeof(t_lst_db) - 1)) == NULL)
		return (NULL);
	if (cont == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ptr = NULL;
		if ((ptr = (void*)ft_strnew(cont_size)) == NULL)
			return (NULL);
		ft_memcpy(ptr, cont, cont_size);
		new->content = ptr;
		new->content_size = cont_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
