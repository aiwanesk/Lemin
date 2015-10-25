/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 16:28:10 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/07 11:47:36 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define TC ((t_salle *)link->content)

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

void		run(t_list *list, int ant)
{
	int	tot;

	tot = 1;
	ant = get_ant();
	while (tot <= ant)
	{
		add_simple(tot, list);
		ft_putchar('\n');
		move_simple(list);
		clean_last(list);
		clean_useless(list);
		tot++;
	}
	while (som_in(list) == 1)
	{
		ft_putchar('\n');
		move_simple(list);
		clean_last(list);
		clean_useless(list);
	}
	ft_putchar('\n');
}

void		replace(char **str, t_list *list, int ant)
{
	t_list	*link;
	int		i;

	i = 0;
	link = list;
	while (str[i])
	{
		TC->name = change_name(str[i], link);
		link = link->next;
		i++;
	}
	i--;
	change_status(list, i, ant);
}

static void	single_path_norme(int i, char *str, t_list *list, int ant)
{
	i--;
	str[i] = '\0';
	replace(ft_strsplit(str, ','), list, ant);
	exit(0);
}

void		single_path(t_list *list, int ant)
{
	t_list	*link;
	t_salle	*s;
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 1000);
	link = list;
	s = TC;
	while (TC->status != END)
	{
		link = s->link;
		while (link != NULL && TC->way_value != 1)
		{
			if (TC->status == END)
				break ;
			link = link->next;
		}
		s = TC;
		str = stradd(TC->name, str);
	}
	while (str[i])
		i++;
	single_path_norme(i, str, list, ant);
}
