/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 09:36:31 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 10:17:27 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

static t_list	*norme_iter(t_list *link, int path_length)
{
	while (link != NULL && TC->way_value != path_length)
	{
		link = link->next;
		if (TC->useless == 2 && link->next != NULL)
			link = link->next;
	}
	return (link);
}

static void		is_simple(t_list *link)
{
	link = simple_choice(link);
	if (TC->indice != 0)
		print_move(link);
}

void			iter_path(t_list *list, int path_length)
{
	t_list		*link;
	t_salle		*s;

	link = list;
	while (((t_salle*)link->content)->status != END)
		link = link->next;
	TC->useless = 2;
	((t_salle *)link->content)->dist = 99;
	s = ((t_salle *)link->content);
	link = s->link;
	while (link != NULL && ((t_salle *)link->content)->status != START)
	{
		link = s->link;
		if (choice(link) == 2)
			is_simple(link);
		else
			link = norme_iter(link, path_length);
		TC->useless = 2;
		if (TC->indice != 0)
			print_move(link);
		s = ((t_salle *)link->content);
		link = s->link;
	}
}

void			init_useless(t_list *list)
{
	t_list		*link;

	link = list;
	while (link != NULL)
	{
		if (TC->status == END || TC->status == START)
			TC->useless = 0;
		else if (TC->way_value != 0)
			TC->useless = 0;
		else
			TC->useless = 1;
		link = link->next;
	}
}
