/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:10 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:11 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char*)s;
	while (ptr[i] != '\0')
		i++;
	str = ft_strnew(i);
	str[i] = '\0';
	i = 0;
	while (ptr[i] != '\0')
	{
		str[i] = (*f)(ptr[i]);
		i++;
	}
	return (str);
}
