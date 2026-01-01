/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:51:33 by halalul           #+#    #+#             */
/*   Updated: 2025/12/01 13:37:14 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*rc;
	char		*des;

	rc = src;
	des = dest;
	i = 0;
	while (i < n)
	{
		des[i] = rc[i];
		i++;
	}
	return (des);
}
