/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:41:56 by halalul           #+#    #+#             */
/*   Updated: 2025/12/04 16:42:02 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	while (dlen < dsize && dst[dlen])
		dlen++;
	slen = 0;
	while (src[slen])
		slen++;
	if (dsize == 0 || dlen == dsize)
		return (dlen + slen);
	i = 0;
	while (dlen + i < dsize - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
