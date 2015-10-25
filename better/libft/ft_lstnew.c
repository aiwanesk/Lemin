/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:33 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:34 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*ptr;

	new = NULL;
	if ((new = (t_list*)ft_strnew(sizeof(t_list) - 1)) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ptr = NULL;
		if ((ptr = (void*)ft_strnew(content_size)) == NULL)
			return (NULL);
		ft_memcpy(ptr, content, content_size);
		new->content = ptr;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
