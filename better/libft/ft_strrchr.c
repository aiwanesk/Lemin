/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:39 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:40 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (void *)s;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			str = str + i;
			return (str);
		}
		i--;
	}
	return (NULL);
}
