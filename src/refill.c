/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:33:31 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/15 21:33:31 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check(t_stacks *s, int i)
{
	size_t	j;

	j = 0;
	while (j < s->size_b)
	{
		if (i == s->stack_b[j])
			return (true);
		j++;
	}
	return (false);
}

int	find_min(t_stacks *s)
{
	size_t	i;
	int		min;
	int		min_ind;

	i = 0;
	min = INT_MAX;
	while (i < s->size_a)
	{
		if (check(s, i))
		{
			i++;
			continue ;
		}
		if (s->stack_a[i] <= min)
		{
			min = s->stack_a[i];
			s->stack_b[s->size_b] = i;
			min_ind = i;
		}
		i++;
	}
	s->size_b++;
	return (min_ind);
}

void	refill(t_stacks *s)
{
	int		*arr;
	size_t	i;

	arr = malloc((s->size_a + 1) * 4);
	if (!arr)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "error\n", s);
	i = 0;
	while (i < s->size_a)
		arr[find_min(s)] = i++;
	s->size_b = 0;
	free(s->stack_a);
	s->stack_a = arr;
}
