/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:03 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:04 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(s1);
	i = size;
	if (s1 == NULL || s2 == NULL)
		return (0);
	j = ft_strlen(s2);
	while (*s1 && size)
	{
		s1++;
		size--;
	}
	if (size == 0)
		return (i + j);
	while (*s2 && size > 1)
	{
		*s1 = *s2;
		s1++;
		s2++;
		size--;
	}
	*s1 = '\0';
	return (k + j);
}
