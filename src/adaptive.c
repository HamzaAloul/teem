/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:49:33 by halalul           #+#    #+#             */
/*   Updated: 2026/02/16 23:13:20 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	adaptive(int argc, char **argv, t_stacks *stacks, t_bench *b)
{
	int	i;

	i = 1;
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
		i++;
	not_int_error(argv, i);
	stacks = fill_stack_a(argv, argc, i, b);
	test_if_sort(stacks, argv, b);
	duplicate_error(stacks);
	if (stacks->cost < 0.2)
		selection_sort(stacks, argv, b);
	else if (stacks->cost < 0.5)
	{
		refill(stacks);
		chunke_sort(stacks, 0, argv, b);
	}
	else if (stacks->cost >= 0.5)
	{
		refill(stacks);
		radix(stacks, argv, b);
	}
}
