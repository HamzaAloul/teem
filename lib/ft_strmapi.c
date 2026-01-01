/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:28:38 by halalul           #+#    #+#             */
/*   Updated: 2025/12/08 14:31:07 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ff;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ff = malloc(i + 1);
	if (!ff)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ff[i] = f(i, s[i]);
		i++;
	}
	ff[i] = '\0';
	return (ff);
}
