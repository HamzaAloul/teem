/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:11:18 by halalul           #+#    #+#             */
/*   Updated: 2025/12/04 20:36:54 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	b;
	char	*ar;

	if (!s1 || !s2)
		return (NULL);
	ar = malloc(ft_strlen(s1) + 1 + ft_strlen(s2));
	if (!ar)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ar[i] = s1[i];
		i++;
	}
	b = 0;
	while (s2[b])
	{
		ar[i] = s2[b];
		i++;
		b++;
	}
	ar[i] = '\0';
	return (ar);
}
