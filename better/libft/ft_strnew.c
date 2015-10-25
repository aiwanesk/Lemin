/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:33 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:34 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_malloc(void)
{
	ft_putendl_fd("~~MALLOC FAILLED TO ALLOCATED A MEMORY ZONE~~", 2);
	ft_putendl_fd("Ooops, something went terribly wrong somewhere.", 2);
	ft_putstr_fd("Whatever happened, it is unsafe to continue in this", 2);
	ft_putendl_fd("risky environment.\n\nMALLOC FAILLED: exit with code 12", 2);
	exit(12);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = (int)size;
	if ((str = (char*)malloc(j + 1)) == NULL)
		error_malloc();
	while (i <= j)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
