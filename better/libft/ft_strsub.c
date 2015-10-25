/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:57 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = NULL;
	str = ft_strnew(len);
	if (str == NULL || start + len > ft_strlen(s))
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			str[i - start] = s[i];
		i++;
	}
	return (str);
}
