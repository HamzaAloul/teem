/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:16:18 by halalul           #+#    #+#             */
/*   Updated: 2026/02/05 16:48:27 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

double	compute_disorder(t_stacks *stacks)
{
	double	mistakes;
	int		total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < (stacks->size_a))
	{
		j = i + 1;
		while (j < (stacks->size_a))
		{
			total_pairs++;
			if ((stacks->stack_a)[i] > (stacks->stack_a)[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
