/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 14:48:29 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 16:46:25 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

void		clean_end(t_list *list)
{
	t_list		*link;

	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	(((t_salle *)link->content)->indice) = 0;
}

static void	move_next(t_list *link)
{
	while (link != NULL)
	{
		if (TC->clean == 2)
			TC->clean = 1;
		link = link->next;
	}
}

int			move(t_list *list)
{
	t_list		*link;
	int			ret;

	ret = 0;
	link = list;
	clean_end(list);
	while (link != NULL)
	{
		if (((t_salle *)link->content)->status == END)
		{
			if (link->next != NULL)
				link = link->next;
			else
				break ;
		}
		if (((t_salle *)link->content)->clean == 1)
		{
			iter_path(list, TC->way_value);
			init_useless(list);
			ret = 1;
		}
		link = link->next;
	}
	move_next(list);
	return (ret);
}
