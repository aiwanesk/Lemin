/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:10:58 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:10:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = NULL;
	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	k = 0;
	str = ft_strnew(i + j);
	if (str != NULL)
		while (k <= i + j)
		{
			if (k < i)
				str[k] = s1[k];
			if (k >= i && k != i + j)
				str[k] = s2[k - i];
			if (k == i + j)
				str[k] = '\0';
			k++;
		}
	return (str);
}
