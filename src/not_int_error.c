/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_int_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:28 by halalul           #+#    #+#             */
/*   Updated: 2026/02/12 20:33:32 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	whil(char **npr)
{
	int	j;
	int	jj;

	j = 0;
	while (npr[j])
	{
		jj = 0;
		while (npr[j][jj])
		{
			if (jj == 0 && (npr[j][0] == '+' || npr[j][0] == '-'))
				jj++;
			if (!(ft_isdigit(npr[j][jj])))
			{
				ft_printf("Error\n");
				exit(1);
			}
			jj++;
		}
		j++;
	}
}

void	not_int_error(char **argv, int i)
{
	char	**npr;

	while (argv[i])
	{
		npr = ft_split(argv[i], ' ');
		whil(npr);
		i++;
	}
}
