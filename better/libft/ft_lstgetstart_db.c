/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetstart_db.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:00 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:02 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstgetstart_db(t_lst_db **lst)
{
	if (lst && *lst)
		while ((*lst)->prev)
			*lst = (*lst)->prev;
	return (*lst);
}
