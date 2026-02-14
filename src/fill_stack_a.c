/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:01:52 by halalul           #+#    #+#             */
/*   Updated: 2026/02/12 15:14:53 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	loop(t_stacks *stacks, char **argv, int argc, int i)
{
	int		j;
	int		jj;
	char	**npr;

	j = 0;
	while (i < argc)
	{
		npr = ft_split(argv[i], ' ');
		jj = 0;
		while (npr[jj])
		{
			stacks->stack_a[j] = ft_atoi(npr[jj]);
			jj++;
			j++;
		}
		i++;
	}
}

t_stacks	*fill_stack_a(char **argv, int argc, int i)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit_free_stacks(1, "Error\n", stacks);
	stacks->size_a = len_arr(argv, argc, i);
	stacks->stack_a = malloc(sizeof(int) * stacks->size_a);
	stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
	stacks->size_b = 0;
	if (!stacks->stack_a)
		exit_free_stacks(1, "Error\n", stacks);
	loop(stacks, argv, argc, i);
	stacks->cost = compute_disorder(stacks);
	return (stacks);
}
