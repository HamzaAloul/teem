/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:43:56 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/11 17:38:59 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	black_char(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (black_char(s1[start], set) && s1[start])
		start++;
	while (black_char(s1[end], set) && end > start)
		end--;
	if (start > end)
		return (ft_calloc(1, 1));
	p = (char *)malloc(end - start + 2);
	if (!p)
		return (NULL);
	while (start <= end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
