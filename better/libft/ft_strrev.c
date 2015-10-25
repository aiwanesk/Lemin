/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:44 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	if ((temp = ft_strnew(i)) == NULL)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	ft_strcpy(str, temp);
	free(temp);
	return (str);
}
