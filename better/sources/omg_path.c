/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omg_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 03:37:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 10:19:27 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define CNT ((t_salle *)link->content)

static t_salle		*is_path(t_salle *salle, int value)
{
	int			ret;
	t_list		*link;
	t_salle		*temp;

	link = salle->link;
	ret = -1;
	salle->way_value = value;
	temp = NULL;
	while (link != NULL)
	{
		if ((ret == -1 && CNT->way_value == 0) || (ret > (CNT)->dist &&
					CNT->way_value == 0))
		{
			temp = CNT;
			ret = (CNT)->dist;
		}
		link = link->next;
	}
	return (temp);
}

static int			path_avaiable(t_list *list)
{
	t_salle		*path;
	t_list		*l;
	int			i;

	i = 0;
	path = ((t_salle *)list->content);
	l = path->link;
	while (l != NULL)
	{
		if (((t_salle *)l->content)->way_value == 0)
			i++;
		l = l->next;
	}
	return (i);
}

static int			how_many_valid(t_list *list)
{
	t_list	*link;
	t_salle	*s;
	int		i;

	link = list;
	i = 0;
	while (((t_salle *)link->content)->status != START)
		link = link->next;
	s = (t_salle *)link->content;
	link = s->link;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->way_value != 0)
			i++;
		link = link->next;
	}
	return (i);
}

static int			preliminary_check(t_list *list)
{
	t_list		*link;

	link = ((t_salle *)list->content)->link;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->status == END)
			return (1);
		link = link->next;
	}
	return (0);
}

void				omg(t_list *list, int value, int ant)
{
	t_list		*link;
	t_salle		*path;
	t_list		*start;

	value = 1;
	link = list;
	start = list;
	is_possible(list);
	if (preliminary_check(list) == 1)
		fast_end(list, ant);
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = CNT;
	while (path_avaiable(link) >= 1)
	{
		while (path && path->status != START)
			path = is_path(path, value);
		reinit_dist(start);
		give_value((t_salle*)start->content);
		((t_salle *)list->content)->dist = 0;
		value++;
		path = ((t_salle *)link->content);
	}
	print(list, how_many_valid(list), ant);
}
