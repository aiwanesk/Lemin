/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_path_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:45:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 10:50:17 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

void		move_basic(t_list *link)
{
	int		i;

	i = TC->indice;
	TC->indice = 0;
	link = link->next;
	TC->indice = i;
	ft_putstr("\033[33mL");
	ft_putnbr(TC->indice);
	ft_putstr("-");
	ft_putstr(TC->name);
	ft_putstr("\033[40m ");
	TC->useless = 2;
}

void		move_simple(t_list *list)
{
	t_list		*link;
	t_salle		*s;
	t_list		*temp;
	int			i;

	link = list;
	temp = NULL;
	s = TC;
	i = 0;
	while (link != NULL)
	{
		if (TC->indice != 0 && TC->useless != 2)
		{
			temp = link;
			i++;
		}
		link = link->next;
	}
	if (temp != NULL)
		move_basic(temp);
	if (i >= 1)
		move_simple(list);
}

void		spag(t_list *list)
{
	t_list	*link;

	link = list;
	while (link != NULL)
	{
		if (TC->status == START)
			exit(0);
		link = link->next;
	}
}
