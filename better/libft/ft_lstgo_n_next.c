/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgo_n_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:05 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:06 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstgo_n_next(t_lst_db *lst, int n)
{
	if (lst)
		while (lst->next && n)
		{
			lst = lst->next;
			n--;
		}
	return (lst);
}
