/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 02:10:16 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:15:26 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(t_stacks *s, char **argv, t_bench *b)
{
	size_t	i;
	int		bit;

	bit = 0;
	while (true)
	{
		i = s->size_a;
		while (i > 0)
		{
			if ((s->stack_a[0] >> bit) & 1)
				ra(s, b);
			else if (s->size_a > 1)
				pb(s, b);
			i--;
		}
		while (s->size_b)
			pa(s, b);
		test_if_sort(s, argv, b);
		bit++;
	}
}
