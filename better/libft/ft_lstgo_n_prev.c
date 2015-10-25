/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgo_n_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:07:16 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:07:17 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstgo_n_prev(t_lst_db *lst, int n)
{
	if (lst)
		while (lst->next && n)
		{
			lst = lst->prev;
			n--;
		}
	return (lst);
}
