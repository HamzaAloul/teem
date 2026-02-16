/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            +:+      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 02:10:16 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 02:10:16 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(t_stacks *s)
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
				ra(s);
			else if (s->size_a > 1)
				pb(s);
			i--;
		}
		while (s->size_b)
			pa(s);
		test_if_sort(s);
		bit++;
	}
}
