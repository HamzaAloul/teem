/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:27:18 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/09 20:17:20 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_to_begin(const char *s);

int	ft_atoi(const char *nptr)
{
	size_t		i;
	size_t		sign;
	int			num;

	num = 0;
	i = 0 + ft_to_begin(nptr);
	if (nptr[i] == '\0')
		return (0);
	sign = i;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		if (ft_isdigit(nptr[i]))
		{
			num *= 10;
			num += (nptr[i] - '0');
		}
		i++;
	}
	if (ft_memcmp(nptr + sign, "-2147483648", 11) == 0)
		return (-2147483648);
	if (nptr[sign] == '-')
		return (((int)(num)) * -1);
	return (num);
}

static size_t	ft_to_begin(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || ft_isdigit(s[i]) || s[i] == '+')
		return (i);
	else
		return (ft_strlen(s));
}
