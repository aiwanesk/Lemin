/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:11:47 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:11:49 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			k++;
		i++;
	}
	return (k);
}

static char		*write_str(char const *s, char c, int *lgt, char *str)
{
	int a;
	int b;

	b = 0;
	while (s[(*lgt)] == c && s[(*lgt)])
		*lgt = *lgt + 1;
	while (s[b + *lgt] != c && s[*lgt + b])
		b++;
	str = ft_strnew(b + 1);
	if (!str)
		return (0);
	a = 0;
	while (s[(*lgt)] != c && s[(*lgt)])
	{
		str[a] = s[(*lgt)];
		*lgt = *lgt + 1;
		a++;
	}
	str[a] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = 0;
	if (s)
	{
		k = count_str(s, c);
		tab = (char**)ft_tabnew(k);
	}
	if (!tab)
		return (NULL);
	while (i < k)
	{
		tab[i] = write_str(s, c, &j, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
