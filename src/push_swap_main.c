/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:12:17 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/17 15:12:29 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bench	*fill_b(void)
{
	t_bench	*b;

	b = malloc(sizeof(t_bench));
	if (!b)
		return (NULL);
	b->strategy = malloc(15);
	if (!b)
	{
		free(b);
		return (NULL);
	}
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
	b->total = 0;
	return (b);
}

static void	ev_thing2(int argc, char **argv, t_stacks *stacks, t_bench *cbench)
{
	int	i;

	i = 1;
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
		i++;
	if (ft_strncmp(argv[i], "--complex", 9) == 0)
	{
		cbench->strategy = "complex";
		not_int_error(argv, i + 1);
		stacks = fill_stack_a(argv, argc, i + 1, cbench);
		test_if_sort(stacks, argv, cbench);
		duplicate_error(stacks);
		refill(stacks);
		radix(stacks, argv, cbench);
	}
	else
	{
		cbench->strategy = "adaptive";
		adaptive(argc, argv, stacks, cbench);
	}
}

static void	ev_thing(int argc, char **argv, t_stacks *stacks, t_bench *cbench)
{
	int	i;

	i = 1;
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
		i++;
	if (ft_strncmp(argv[i], "--medium", 8) == 0)
	{
		cbench->strategy = "medium";
		not_int_error(argv, i + 1);
		stacks = fill_stack_a(argv, argc, i + 1, cbench);
		test_if_sort(stacks, argv, cbench);
		duplicate_error(stacks);
		refill(stacks);
		chunke_sort(stacks, 0, argv, cbench);
	}
	ev_thing2(argc, argv, stacks, cbench);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_bench		*cbench;
	int			i;

	if (argc < 2)
		return (0);
	i = 1;
	cbench = fill_b();
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
		i++;
	if (i == argc)
		return (0);
	if (ft_strncmp(argv[i], "--simple", 8) == 0)
	{
		cbench->strategy = "simple";
		not_int_error(argv, i + 1);
		stacks = fill_stack_a(argv, argc, i + 1, cbench);
		test_if_sort(stacks, argv, cbench);
		duplicate_error(stacks);
		selection_sort(stacks, argv, cbench);
	}
	ev_thing(argc, argv, stacks, cbench);
	return (0);
}
