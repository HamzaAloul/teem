/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 02:24:54 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/09 00:06:49 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*a = s;
	unsigned char		uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (a[i] == uc)
			return ((void *)(a + i));
		i++;
	}
	return (NULL);
}
