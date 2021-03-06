/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:36 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:37 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)s1;
	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (str + i);
	while (s1[i] != '\0' && n > i)
	{
		while (s1[i + j] == s2[j] && (n > i + j))
		{
			j++;
			if (s2[j] == '\0')
				return (str + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
