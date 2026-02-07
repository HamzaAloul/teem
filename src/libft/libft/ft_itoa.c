/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:15:07 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/11 17:42:02 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(int n)
{
	size_t	l;

	l = 0;
	if (n < 0)
		l++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t	l;
	char	*p;
	long	ln;

	ln = n;
	l = len(n);
	p = (char *)malloc(l + 1);
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		ln = -ln;
	}
	p[l] = '\0';
	if (n == 0)
		p[0] = '0';
	while (ln != 0)
	{
		l--;
		p[l] = (ln % 10) + '0';
		ln = ln / 10;
	}
	return (p);
}
