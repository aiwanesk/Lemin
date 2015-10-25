/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 14:30:28 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 09:49:45 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	get_tot(int *ant_per_path, int len)
{
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while (i < len)
	{
		ret = ret + ant_per_path[i];
		i++;
	}
	return (ret);
}

static int	som_in(t_list *list)
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

static void	move_ant_next(t_list *list)
{
	ft_putchar('\n');
	move_end(list);
	if (som_in(list) == 1)
		move(list);
}

static void	else_move_ant(int tot, int *ant_per_path, t_list *list, int len)
{
	int			i;
	int			name;

	name = 1;
	while (tot > 0)
	{
		i = -1;
		while (++i < len)
		{
			if (ant_per_path[i] > 0)
			{
				add_ant(name, list, i + 1);
				ant_per_path[i]--;
				tot--;
				name++;
			}
		}
		move_ant_next(list);
	}
}

void		move_ant(int *ant_per_path, t_list *list, int len)
{
	int					tot;

	tot = get_tot(ant_per_path, len);
	init_clean(list);
	if (tot <= 10)
		len = 1;
	if (len == 1)
		single_path(list, ant_per_path[0]);
	else
		else_move_ant(tot, ant_per_path, list, len);
	while (som_in(list) == 1)
		move_ant_next(list);
	ft_putchar('\n');
}
