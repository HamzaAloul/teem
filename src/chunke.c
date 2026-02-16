/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunke.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:34:25 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:14:09 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_max(t_stacks *s)
{
	size_t	i;
	int		max;

	max = s->stack_b[0];
	i = 0;
	while (i < s->size_b)
	{
		if (s->stack_b[i] > max)
			max = s->stack_b[i];
		i++;
	}
	return (max);
}

static size_t	find_pos(t_stacks *s, int val)
{
	size_t	i;

	i = 0;
	while (i < s->size_b)
	{
		if (s->stack_b[i] == val)
			return (i);
		i++;
	}
	return (0);
}

static int	chunke(t_stacks *s)
{
	int	i;

	i = 0;
	while ((i * i) <= s->size_a)
		i++;
	return (i - 1);
}

static void	revers_selection(t_stacks *s, char **argv, t_bench *b)
{
	int		max;
	size_t	pos;

	while (s->size_b > 0)
	{
		max = find_max(s);
		pos = find_pos(s, max);
		if (pos <= s->size_b / 2)
			while (pos--)
				rb(s, b);
		else
		{
			pos = s->size_b - pos;
			while (pos--)
				rrb(s, b);
		}
		pa(s, b);
	}
	test_if_sort(s, argv, b);
}

void	chunke_sort(t_stacks *s, int min, char **argv, t_bench *b)
{
	const int	chunke_size = chunke(s);
	int			max;
	size_t		i;

	max = chunke_size;
	while (s->size_a)
	{
		i = s->size_a;
		while (i > 0)
		{
			if (s->stack_a[0] <= max && s->stack_a[0] >= min)
				pb(s, b);
			else
				ra(s, b);
			i--;
		}
		min += chunke_size;
		max += chunke_size;
	}
	revers_selection(s, argv, b);
}
