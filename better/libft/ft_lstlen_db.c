/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:27 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen_db(t_lst_db *lst)
{
	int	i;

	i = 0;
	lst = ft_lstgetstart_db(&lst);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
