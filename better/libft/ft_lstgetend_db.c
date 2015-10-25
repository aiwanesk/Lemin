/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetend_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:06:57 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:06:58 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstgetend_db(t_lst_db **lst)
{
	if (lst && *lst)
		while ((*lst)->next)
			*lst = (*lst)->next;
	return (*lst);
}
