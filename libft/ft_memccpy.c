/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:55 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:57 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*sourc;

	sourc = src;
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		if (sourc[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
