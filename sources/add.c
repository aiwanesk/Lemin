/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 13:59:17 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 09:17:20 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_move_add(t_list *list)
{
	if (((t_salle *)list->content)->way_value == 1)
	{
		ft_putstr("\033[46mL");
		ft_putnbr(((t_salle *)list->content)->indice);
		ft_putstr("-");
		ft_putstr(((t_salle *)list->content)->name);
		ft_putstr("\033[40m ");
	}
	else
	{
		ft_putstr("\033[45mL");
		ft_putnbr(((t_salle *)list->content)->indice);
		ft_putstr("-");
		ft_putstr(((t_salle *)list->content)->name);
		ft_putstr("\033[40m ");
	}
}

void			add_ant(int name, t_list *list, int path)
{
	t_list		*link;
	t_salle		*p;

	p = ((t_salle *)list->content);
	link = p->link;
	while (((t_salle *)link->content)->way_value != path)
	{
		link = link->next;
	}
	((t_salle *)link->content)->indice = name;
	((t_salle *)link->content)->used = path;
	((t_salle *)link->content)->clean = 1;
	print_move_add(link);
}

void			init_clean(t_list *list)
{
	t_list		*link;

	link = list;
	while (link != NULL)
	{
		(((t_salle *)link->content)->clean) = 0;
		(((t_salle *)link->content)->indice) = 0;
		link = link->next;
	}
}
