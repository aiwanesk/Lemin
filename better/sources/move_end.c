/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 13:57:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 16:17:40 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	move_end_next(t_list *safe, int which, t_salle *s)
{
	if (which == 1)
	{
		ft_putstr("\033[32mL");
		ft_putnbr(s->indice);
		ft_putstr("-");
		ft_putstr(((t_salle *)safe->content)->name);
		ft_putstr("\033[37m ");
	}
	else
	{
		ft_putstr("\033[33mL");
		ft_putnbr(s->indice);
		ft_putstr("-");
		ft_putstr(((t_salle *)safe->content)->name);
		ft_putstr("\033[37m ");
	}
}

void		move_end(t_list *list)
{
	t_list		*link;
	t_list		*safe;
	t_salle		*s;

	link = list;
	while (link != NULL && ((t_salle *)link->content)->status != END)
		link = link->next;
	safe = link;
	s = ((t_salle *)link->content);
	link = s->link;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->indice != 0)
		{
			s = ((t_salle *)link->content);
			if (((t_salle *)link->content)->way_value == 1)
				move_end_next(safe, 1, s);
			else
				move_end_next(safe, 2, s);
			s->indice = 0;
		}
		link = link->next;
	}
}
