/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:38:20 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/11 15:35:30 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_if_sort(t_stacks *stacks)
{
	size_t	size;

	size = 0;
	while (size < stacks->size_a - 1)
	{
		if (stacks->stack_a[size] < stacks->stack_a[size + 1])
			size++;
		else
			return ;
	}
	exit_free_stacks(EXIT_SUCCESS, "error\n", stacks);
}

void	bubble(t_stacks *stacks)
{
	size_t	size;
	size_t	end;

	end = stacks->size_a;
	while (end > 0)
	{
		size = 0;
		while (size + 1 < stacks->size_a)
		{
			if (stacks->stack_a[0] > stacks->stack_a[1])
				sa(stacks);
			ra(stacks);
			size++;
		}
		end--;
		test_if_sort(stacks);
	}
}
