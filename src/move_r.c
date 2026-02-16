/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:33:21 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:16:13 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_ra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = stacks->stack_a[0];
	while (i < (stacks->size_a - 1))
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
}

static void	move_rb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = stacks->stack_b[0];
	while (i < (stacks->size_b - 1))
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}

void	ra(t_stacks *stacks, t_bench *b)
{
	ft_printf("ra\n");
	b->ra++;
	b->total++;
	if (stacks->size_a <= 1)
		return ;
	move_ra(stacks);
}

void	rb(t_stacks *stacks, t_bench *b)
{
	ft_printf("rb\n");
	b->rb++;
	b->total++;
	if (stacks->size_b <= 1)
		return ;
	move_rb(stacks);
}

void	rr(t_stacks *stacks, t_bench *b)
{
	ft_printf("rr\n");
	b->rr++;
	b->total++;
	if (stacks->size_a > 1)
	{
		move_ra(stacks);
	}
	if (stacks->size_b > 1)
	{
		move_rb(stacks);
	}
}
