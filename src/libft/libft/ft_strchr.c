/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:56:29 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/02 17:00:56 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	a;

	a = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == a)
			return ((char *)(s + i));
		i++;
	}
	if (a == '\0')
		return ((char *)(s + i));
	return (NULL);
}
