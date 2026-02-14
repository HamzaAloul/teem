/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:55 by halalul           #+#    #+#             */
/*   Updated: 2026/02/05 16:45:31 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_atoi(const char *nptr)
{
	long	n;
	long	s;
	long	i;

	i = 0;
	n = 0;
	s = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	i = n * s;
	if (i < -2147483648 || i > 2147483647)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (i);
}
