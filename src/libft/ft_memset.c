/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:59:30 by mabu-are          #+#    #+#             */
/*   Updated: 2025/11/27 21:12:17 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*start;
	unsigned char	*end;

	start = (unsigned char *)str;
	end = (unsigned char *)(str + n);
	while (start < end)
		*start++ = c;
	return (str);
}
