/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:55 by halalul           #+#    #+#             */
/*   Updated: 2025/12/04 17:56:06 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c(const char *big, const char *little, size_t i, size_t len)
{
	size_t	o;
	int		s;

	o = 0;
	s = 1;
	while (little[o] && s && (i + o) < len)
	{
		if (big[i + o] != little[o])
			s = 0;
		o++;
	}
	if (little[o] == '\0' && s == 1)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (c(big, little, i, len))
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
