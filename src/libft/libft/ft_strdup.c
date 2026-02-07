/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:14:07 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/02 17:27:33 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s) + 1;
	dst = (char *)malloc(i);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, i);
	return (dst);
}
