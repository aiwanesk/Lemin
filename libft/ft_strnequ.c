/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:29 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:30 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
