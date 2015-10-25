/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:09:33 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:09:33 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;

	sourc = (void *)src;
	dest = dst;
	if (dest <= sourc)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		n--;
		dest[n] = sourc[n];
	}
	return (dst);
}
