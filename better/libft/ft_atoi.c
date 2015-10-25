/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:05:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/09/02 14:05:38 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (nbr < -214748364 || (nbr == -214748364 && str[i] >= '9'))
			return (-1);
		else if (nbr > 214748364 || (nbr == 214748364 && str[i] >= '8'))
			return (-1);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
