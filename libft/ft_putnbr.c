/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:09:57 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:09:58 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * (-1);
		}
		if (nbr >= 10)
			ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}
