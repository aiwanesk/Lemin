/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 01:53:58 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 09:40:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

int				choice(t_list *list)
{
	t_list		*link;
	int			i;

	i = 0;
	link = list;
	while (link != NULL)
	{
		i++;
		link = link->next;
	}
	return (i);
}

t_list			*simple_choice(t_list *link)
{
	t_list		*list;
	int			cmp;

	cmp = -1;
	list = link;
	if (((t_salle *)list->content)->status == END)
	{
		list = list->next;
		return (list);
	}
	else
		return (list);
	while (list != NULL)
	{
		if (cmp == -1 || cmp < ((t_salle *)list->content)->dist)
			cmp = ((t_salle *)list->content)->dist;
		list = list->next;
	}
	while (link != NULL)
	{
		if (TC->dist == cmp)
			break ;
		link = link->next;
	}
	return (list);
}

static int		*choose_path(int *every_path, int ant)
{
	float			ret;
	float			cmp;
	float			a;
	float			diff_len;
	int				*tab;

	tab = (int *)malloc(sizeof(int) * 2);
	diff_len = every_path[1] - every_path[0];
	a = ant - diff_len;
	cmp = a / 2;
	ret = cmp + diff_len;
	if (ret - (int)ret > 0)
	{
		ret = (int)ret + 1;
		cmp = (int)cmp;
	}
	tab[0] = ret;
	tab[1] = cmp;
	return (tab);
}

static void		exception(int ant, int *print, t_list *list)
{
	print[0] = ant;
	print[1] = 1;
	move_ant(print, list, 1);
	exit(0);
}

void			compute_way(int ant, int *every_path, int len, t_list *list)
{
	int			nb;
	int			*print;
	int			*ret;

	ret = (int *)malloc(sizeof(int) * 2);
	if (len > 2)
		len = 2;
	print = (int *)malloc(sizeof(int) * len);
	nb = ant + every_path[0] - 1;
	print[0] = nb;
	init_useless(list);
	if (len == 1)
		exception(ant, print, list);
	else if (nb > every_path[1])
	{
		ret = choose_path(every_path, ant);
		print[0] = ret[0];
		print[1] = ret[1];
	}
	else
	{
		print[0] = ant;
		print[1] = 0;
	}
	move_ant(print, list, len);
}
