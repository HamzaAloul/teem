/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:25:36 by halalul           #+#    #+#             */
/*   Updated: 2026/02/05 19:33:43 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	len_arr(char **argv, int argc)
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
			j++;
			jj++;
		}
		i++;
	}
	return (j);
}
