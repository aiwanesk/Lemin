/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:10:19 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:10:20 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*vi;

	vi = (char*)s;
	i = 0;
	while (i == 0 || s[i - 1] != '\0')
	{
		if (s[i] == c)
			return (vi + i);
		i++;
	}
	return (NULL);
}
