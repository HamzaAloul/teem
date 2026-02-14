/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:50:24 by halalul           #+#    #+#             */
/*   Updated: 2026/02/12 14:56:46 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	loop(int i, int *nb, t_stacks *stacks)
{
	int		er;
	size_t	j;

	j = 0;
	er = 0;
	while (j < stacks->size_a)
	{
		if (nb[i] == stacks->stack_a[j])
			er++;
		j++;
	}
	if (er == 2)
		exit_free_stacks(3, "Error\n", stacks);
}

void	duplicate_error(t_stacks *stacks)
{
	size_t	i;
	int		*nb;

	i = 0;
	nb = malloc(sizeof(int) * stacks->size_a);
	if (!nb)
		return ;
	while (i < stacks->size_a)
	{
		nb[i] = stacks->stack_a[i];
		loop(i, nb, stacks);
		i++;
	}
}
