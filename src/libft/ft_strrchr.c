/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:27:42 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/02 23:20:08 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
