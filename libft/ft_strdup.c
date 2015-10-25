/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:10:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:10:43 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	s2 = ft_strnew(i);
	while (j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && n >= i)
		i++;
	s2 = ft_strnew(i);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
