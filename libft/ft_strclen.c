/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:10:22 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:10:23 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclen(const char *s, int c)
{
	size_t	size;

	size = 0;
	if (s == NULL)
		return (-1);
	while (s[size] != '\0' && s[size] != (unsigned char)c)
		size++;
	if (s[size] == (unsigned char)c)
		return (size);
	return (-1);
}
