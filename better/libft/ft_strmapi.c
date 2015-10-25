/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:14 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:14 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	ptr = (char*)s;
	while (ptr[i])
		i++;
	str = ft_strnew(i);
	i = 0;
	while (ptr[i])
	{
		str[i] = (*f)(i, ptr[i]);
		i++;
	}
	return ((char*)str);
}
