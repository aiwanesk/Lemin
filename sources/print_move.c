/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 13:51:52 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:01:22 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	print_move_next(t_list *link)
{
	ft_putstr("\033[96mL");
	ft_putnbr(((t_salle *)link->content)->indice);
	ft_putstr("-");
	ft_putstr(((t_salle *)link->content)->name);
	ft_putstr("\033[37m ");
}

void		print_move(t_list *list)
{
	int			save_name;
	t_list		*link;
	t_salle		*s;

	save_name = ((t_salle *)list->content)->indice;
	((t_salle *)list->content)->indice = 0;
	s = ((t_salle *)list->content);
	link = ((t_salle *)list->content)->link;
	while (((t_salle *)link->content)->useless != 2)
		link = link->next;
	((t_salle *)link->content)->indice = save_name;
	if (((t_salle *)link->content)->way_value == 1)
	{
		ft_putstr("\033[95mL");
		ft_putnbr(((t_salle *)link->content)->indice);
		ft_putstr("-");
		ft_putstr(((t_salle *)link->content)->name);
		ft_putstr("\033[37m ");
	}
	else
		print_move_next(link);
}
