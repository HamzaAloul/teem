/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:43:57 by halalul           #+#    #+#             */
/*   Updated: 2025/12/04 16:44:02 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	s;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (dsize == 0)
	{
		return (i);
	}
	dsize--;
	s = 0;
	while (dsize > s && src[s])
	{
		dst[s] = src[s];
		s++;
	}
	dst[s] = '\0';
	return (i);
}
