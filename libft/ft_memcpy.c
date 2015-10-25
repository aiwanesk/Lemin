/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:09:20 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:09:22 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*sourc;

	sourc = (void *)src;
	dest = dst;
	i = 0;
	while (i < n && (dest + i))
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dest);
}
