/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:12:17 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/05 20:15:06 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	fill_stack_a(int **a, char **argv, int argc)
{
	int		i;
	int		j;
	int		jj;
	char	**npr;

	i = 1;
	j = 0;
	while (i < argc)
	{
		npr = ft_split(argv[i], ' ');
		jj = 0;
		while (npr[jj])
		{
			(*a)[j] = ft_atoi(npr[jj]);
			jj++;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	not_int_error(argv);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->size_a = len_arr(argv, argc);
	stacks->stack_a = malloc(sizeof(int) * stacks->size_a);
	if (!stacks)
		return (0);
	fill_stack_a(&(stacks->stack_a), argv, argc);
	duplicate_error(stacks);
	return (0);
}
