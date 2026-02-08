/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:59:22 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/10 18:07:40 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)(big));
	while (i < len && big[i])
	{
		if (i + ft_strlen(little) <= len
			&& ft_strncmp(big + i, little, ft_strlen(little)) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
