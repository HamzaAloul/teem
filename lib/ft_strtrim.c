/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:40:00 by halalul           #+#    #+#             */
/*   Updated: 2025/12/05 00:02:52 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in(char const *s1, char const *set, size_t i)
{
	size_t	s;

	s = 0;
	while (set[s])
	{
		if (s1[i] == set[s])
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	q;
	size_t	z;
	char	*arr;

	i = 0;
	q = 0;
	z = 0;
	if (!s1)
		return (NULL);
	while (s1[q])
		q++;
	while (i < q && in(s1, set, i))
		i++;
	while (i < q && in(s1, set, q - 1))
		q--;
	arr = malloc(q - i + 1);
	if (!arr)
		return (NULL);
	while (i < q)
	{
		arr[z++] = s1[i++];
	}
	arr[z] = '\0';
	return (arr);
}
