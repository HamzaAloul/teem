/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:50:24 by halalul           #+#    #+#             */
/*   Updated: 2026/02/05 20:13:47 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	loop(int i, int size, int *nb, int *n)
{
	int	er;
	int	j;

	j = 0;
	er = 0;
	while (j < size)
	{
		if (nb[i] == n[j])
			er++;
		j++;
	}
	if (er == 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	duplicate_error(int *n, int size)
{
	int	i;
	int	*nb;

	i = 0;
	nb = malloc(sizeof(int) * size);
	if (!nb)
		return ;
	while (i < size)
	{
		nb[i] = n[i];
		loop(i, size, nb, n);
		i++;
	}
}
