/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 08:38:20 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:17:30 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* test if the stacks sorted and free all the stacks & exit */
void	test_if_sort(t_stacks *stacks, char **argv, t_bench *b)
{
	size_t	size;

	if (stacks->size_a < 2 && stacks->size_b == 0)
	{
		bench(argv, b);
		exit_free_stacks(EXIT_SUCCESS, "", stacks);
	}
	size = 0;
	while (size < stacks->size_a - 1)
	{
		if (stacks->stack_a[size] < stacks->stack_a[size + 1])
			size++;
		else
			return ;
	}
	bench(argv, b);
	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}

/* find the minimum value in stack A */
static int	find_min(t_stacks *s)
{
	size_t	i;
	int		min;

	min = s->stack_a[0];
	i = 0;
	while (i < s->size_a)
	{
		if (s->stack_a[i] < min)
			min = s->stack_a[i];
		i++;
	}
	return (min);
}

/* find the position of a value in stack A */
static size_t	find_pos(t_stacks *s, int val)
{
	size_t	i;

	i = 0;
	while (i < s->size_a)
	{
		if (s->stack_a[i] == val)
			return (i);
		i++;
	}
	return (0);
}

void	short_sort(t_stacks *s, char **argv, t_bench *bb)
{
	int	a;
	int	b;
	int	c;

	test_if_sort(s, argv, bb);
	if (s->size_a == 2)
	{
		sa(s, bb);
		test_if_sort(s, argv, bb);
	}
	a = s->stack_a[0];
	b = s->stack_a[1];
	c = s->stack_a[2];
	if (a > b && a > c)
		ra(s, bb);
	else if (b > a && b > c)
		rra(s, bb);
	if (s->stack_a[0] > s->stack_a[1])
		sa(s, bb);
}

/* Selection Sort using stack_b as temporary storage */
void	selection_sort(t_stacks *s, char **argv, t_bench *b)
{
	int		min;
	size_t	pos;

	if (s->size_a <= 3)
		short_sort(s, argv, b);
	while (s->size_a > 3)
	{
		min = find_min(s);
		pos = find_pos(s, min);
		if (pos <= s->size_a / 2)
			while (pos--)
				ra(s, b);
		else
		{
			pos = s->size_a - pos;
			while (pos--)
				rra(s, b);
		}
		pb(s, b);
	}
	short_sort(s, argv, b);
	while (s->size_b > 0)
		pa(s, b);
	test_if_sort(s, argv, b);
}
