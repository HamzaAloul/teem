/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:38:21 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/02 20:59:38 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	substr_len = s_len - start;
	if (substr_len > len)
		substr_len = len;
	ptr = (char *)ft_calloc(1, substr_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, substr_len + 1);
	return (ptr);
}
