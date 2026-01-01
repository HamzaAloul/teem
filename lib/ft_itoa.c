/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:17:01 by halalul           #+#    #+#             */
/*   Updated: 2025/12/08 13:17:29 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mall(int n, size_t *i)
{
	int		b;
	char	*nb;

	b = n;
	while (n)
	{
		(*i)++;
		n = n / 10;
	}
	if (b < 0)
	{
		(*i)++;
		nb = malloc(*i + 1);
	}
	else
		nb = malloc(*i + 1);
	if (!nb)
		return (NULL);
	nb[*i] = '\0';
	return (nb);
}

static char	*zero(void)
{
	char	*nb;

	nb = malloc(2);
	if (!nb)
		return (NULL);
	nb[1] = '\0';
	nb[0] = '0';
	return (nb);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*nb;
	long	nr;

	i = 0;
	nr = n;
	if (n == 0)
		return (zero());
	nb = mall(n, &i);
	if (!nb)
		return (NULL);
	if (n < 0)
	{
		nr = -nr;
		nb[0] = '-';
	}
	i--;
	while (nr)
	{
		nb[i--] = (nr % 10) + '0';
		nr = nr / 10;
	}
	return (nb);
}
