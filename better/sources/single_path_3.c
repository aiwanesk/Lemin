/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 16:28:10 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 11:46:40 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

char		*stradd(char *tocopy, char *str)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (tocopy[j])
	{
		str[i] = tocopy[j];
		j++;
		i++;
	}
	str[i] = ',';
	i++;
	str[i] = '\0';
	return (str);
}

char		*change_name(char *str, t_list *list)
{
	int		i;
	t_list	*link;

	i = 0;
	link = list;
	free(TC->name);
	TC->name = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		TC->name[i] = str[i];
		i++;
	}
	return (TC->name);
}

void		clean_useless(t_list *list)
{
	t_list	*link;

	link = list;
	while (link != NULL)
	{
		TC->useless = 0;
		link = link->next;
	}
}

void		add_simple(int tot, t_list *list)
{
	t_list		*link;

	link = list;
	while (TC->status != START)
	{
		link = link->next;
	}
	TC->indice = tot;
	ft_putstr("\033[34mL");
	ft_putnbr(TC->indice);
	ft_putstr("-");
	ft_putstr(TC->name);
	ft_putstr("\033[40m ");
}
