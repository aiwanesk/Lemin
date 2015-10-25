/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:42:51 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 10:47:30 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

void		change_status(t_list *list, int i, int ant)
{
	int		j;
	t_list	*link;

	j = 0;
	link = list;
	while (j < i)
	{
		link = link->next;
		j++;
	}
	((t_salle *)link->content)->status = END;
	link->next = NULL;
	run(list, ant);
}

void		clean_last(t_list *list)
{
	t_list		*link;

	link = list;
	while (link->next != NULL)
		link = link->next;
	TC->indice = 0;
}
