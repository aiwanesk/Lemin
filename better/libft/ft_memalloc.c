/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:49 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = NULL;
	ptr = (unsigned char*)malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void*)ptr);
}
