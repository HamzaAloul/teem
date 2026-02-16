/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:49:33 by halalul           #+#    #+#             */
/*   Updated: 2026/02/16 15:43:21 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	adaptive(int argc, char **argv, int i, t_stacks *stacks)
{
	not_int_error(argv, i);
	stacks = fill_stack_a(argv, argc, i);
	test_if_sort(stacks);
	duplicate_error(stacks);
	if (stacks->cost < 0.2)
		selection_sort(stacks);
	else if (stacks->cost < 0.5)
	{
		refill(stacks);
		chunke_sort(stacks, 0);
	}
	else if (stacks->cost >= 0.5)
	{
		refill(stacks);
		radix(stacks);
	}
}
