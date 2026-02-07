/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          +:+      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:51:01 by mabu-are          #+#    #+#             */
/*   Updated: 2026/01/31 19:51:01 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_rra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
}

static void	move_rrb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
}

void	rra(t_stacks *stacks)
{
	ft_printf("rra\n");
	if (stacks->size_a > 1)
		move_rra(stacks);
}

void	rrb(t_stacks *stacks)
{
	ft_printf("rrb\n");
	if (stacks->size_b > 1)
		move_rrb(stacks);
}

void	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	if (stacks->size_b > 1)
		move_rrb(stacks);
	if (stacks->size_a > 1)
		move_rra(stacks);
}
