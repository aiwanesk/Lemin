/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:47:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 16:44:52 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_dist(t_list *list)
{
	t_list			*yolo;
	t_salle			*salle;

	yolo = list;
	salle = (t_salle *)yolo->content;
	while (yolo != NULL)
	{
		salle = (t_salle *)yolo->content;
		salle->dist = -1;
		salle->way_value = 0;
		salle->simple = 0;
		yolo = yolo->next;
	}
}

void			give_value(t_salle *salle)
{
	t_list		*link;
	t_salle		*test;
	t_list		*temp_link;

	link = salle->link;
	temp_link = link;
	while (link != NULL)
	{
		test = (t_salle *)link->content;
		if ((test->dist > salle->dist + 1 || test->dist == -1)
				&& test->way_value == 0)
		{
			test->dist = salle->dist + 1;
			if (test->status != END)
				give_value(test);
		}
		link = link->next;
	}
}

void			valid_start(t_list *list)
{
	t_list			*link;
	t_salle			*path;

	path = (t_salle *)list->content;
	link = path->link;
	if (path->link == NULL)
	{
		ft_putstr("no link around start\n");
		exit(0);
	}
}

void			resolve(t_list *list, int ant)
{
	int			value;
	t_list		*l;

	l = list;
	value = 1;
	init_dist(list);
	valid_start(list);
	((t_salle*)list->content)->dist = 0;
	give_value((t_salle*)list->content);
	while (l != NULL)
	{
		if (((t_salle *)l->content)->name[0] == 'L')
			ft_error();
		l = l->next;
	}
	if (ant <= 0)
		ft_error();
	omg(list, value, ant);
}
