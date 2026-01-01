/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:43:17 by halalul           #+#    #+#             */
/*   Updated: 2025/12/04 19:41:28 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	n;
	char	*ar;

	n = 0;
	while (s[n])
	{
		n++;
	}
	ar = malloc(n + 1);
	if (!ar)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		ar[i] = s[i];
		i++;
	}
	ar[i] = '\0';
	return (ar);
}
