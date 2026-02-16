/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:12:17 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/14 15:27:38 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ev_thing(int argc, char **argv, int i, t_stacks *stacks)
{
	if (ft_strncmp(argv[i], "--medium", 8) == 0)
	{
		i++;
		not_int_error(argv, i);
		stacks = fill_stack_a(argv, argc, i);
		test_if_sort(stacks);
		duplicate_error(stacks);
		refill(stacks);
		chunke_sort(stacks, 0);
	}
	else if (ft_strncmp(argv[i], "--complex", 9) == 0)
	{
		i++;
		not_int_error(argv, i);
		stacks = fill_stack_a(argv, argc, i);
		test_if_sort(stacks);
		duplicate_error(stacks);
		refill(stacks);
		radix(stacks);
	}
	else
		adaptive(argc, argv, i, stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	i = 1;
	if (ft_strncmp(argv[i], "--bench", 7) == 0)
		i++;
	if (ft_strncmp(argv[i], "--simple", 8) == 0)
	{
		i++;
		not_int_error(argv, i);
		stacks = fill_stack_a(argv, argc, i);
		test_if_sort(stacks);
		duplicate_error(stacks);
		selection_sort(stacks);
	}
	ev_thing(argc, argv, i, stacks);
	return (0);
}
