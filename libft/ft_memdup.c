/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:09:29 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:09:29 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, int len)
{
	char	*dup;

	if ((dup = ft_strnew(len)) == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}
