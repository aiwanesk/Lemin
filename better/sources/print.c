/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 16:04:53 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 16:42:49 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

void		modif_ant_pos(t_list *list, int path_length, int ant_v)
{
	t_list			*link;
	t_list			*refresh;

	link = list;
	while (((t_salle *)link->content)->way_value != path_length)
		link = link->next;
	refresh = link;
	while (((t_salle *)link->content)->way_value != path_length)
		refresh = refresh->next;
	((t_salle *)refresh->content)->indice = 0;
	((t_salle *)refresh->content)->indice = 1;
	ft_putchar('L');
	ft_putnbr(ant_v);
	ft_putchar('-');
	ft_putstr(((t_salle *)link->content)->name);
	ft_putchar('\n');
}

int			someone_in(t_list *list)
{
	t_list		*link;

	link = list;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->indice != 0)
			return (1);
		link = link->next;
	}
	return (0);
}

static int	follow_path(t_list *list, int path_length)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = 0;
	path = ((t_salle *)list->content);
	link = path->link;
	while (path->status != END && (link = path->link))
	{
		while (1)
		{
			if (link == NULL || link->content == NULL || TC->status == END)
				return (ret);
			if (TC->way_value == path_length && TC->dist >= path->dist)
				break ;
			link = link->next;
			if (link == NULL || link->content == NULL || TC->status == END)
				return (0);
		}
		path = ((t_salle *)link->content);
		if (path->status == END)
			return (ret);
		ret++;
	}
	return (ret);
}

void		print(t_list *list, int path, int ant)
{
	int			*possible;
	int			i;
	int			temp_path;

	temp_path = 1;
	possible = (int *)malloc(sizeof(int) * path);
	i = 0;
	while (i < path)
	{
		possible[i] = follow_path(list, temp_path) + 1;
		temp_path++;
		i++;
	}
	if (possible[0] == 0)
		ft_error();
	compute_way(ant, possible, i, list);
	free(possible);
}
