/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:32 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:32 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_db(t_lst_db **alstdb, t_lst_db *nw)
{
	if (alstdb && *alstdb && nw)
	{
		nw->prev = (*alstdb)->prev;
		nw->next = *alstdb;
		if ((*alstdb)->prev)
			(*alstdb)->prev->next = nw;
		(*alstdb)->prev = nw;
		*alstdb = nw;
	}
}
