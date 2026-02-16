/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 02:15:00 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:15:50 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stacks *stacks, t_bench *b)
{
	int	temp;

	ft_printf("sa\n");
	b->sa++;
	b->total++;
	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[1];
	stacks->stack_a[1] = stacks->stack_a[0];
	stacks->stack_a[0] = temp;
}

void	sb(t_stacks *stacks, t_bench *b)
{
	int	temp;

	ft_printf("sb\n");
	b->sb++;
	b->total++;
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[1];
	stacks->stack_b[1] = stacks->stack_b[0];
	stacks->stack_b[0] = temp;
}

void	ss(t_stacks *stacks, t_bench *b)
{
	int	temp;

	ft_printf("ss\n");
	b->ss++;
	b->total++;
	if (stacks->size_a >= 2)
	{
		temp = stacks->stack_a[1];
		stacks->stack_a[1] = stacks->stack_a[0];
		stacks->stack_a[0] = temp;
	}
	if (stacks->size_b >= 2)
	{
		temp = stacks->stack_b[1];
		stacks->stack_b[1] = stacks->stack_b[0];
		stacks->stack_b[0] = temp;
	}
}
