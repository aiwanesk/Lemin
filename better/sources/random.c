/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omg_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 03:37:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 10:49:08 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define CNT ((t_salle *)link->content)

void				fast_end(t_list *list, int ant)
{
	int tot;

	tot = 1;
	while (((t_salle *)list->content)->status != END)
		list = list->next;
	while (ant > 0)
	{
		ft_putstr("\033[32mL");
		ft_putnbr(tot);
		ft_putstr("-");
		ft_putstr(((t_salle *)list->content)->name);
		ft_putstr("\033[37m ");
		ft_putstr("\n");
		tot++;
		ant--;
	}
	exit(0);
}

void				base_check(t_list *list)
{
	t_list		*link;
	t_salle		*s;
	int			i;

	s = ((t_salle *)list->content);
	link = s->link;
	i = 0;
	while (link != NULL)
	{
		if (s->link != NULL && (((t_salle *)link->content)->status) != END)
			i++;
		if (((t_salle *)link->content)->status == END)
			return ;
		link = link->next;
		s = ((t_salle *)list->content);
	}
	if (i == 0)
		ft_error();
}

void				is_possible(t_list *list)
{
	t_list		*link;

	link = list;
	while (link != NULL && ((t_salle *)link->content)->status != END)
		link = link->next;
	if (((t_salle *)link->content)->dist <= 0)
		ft_error();
}
