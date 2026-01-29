/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:59:54 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/18 17:13:09 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_p(int n);

size_t	ft_s_putnbr(int n)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = n;
	if (n <= 0)
		i++;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	ft_putnbr_p(n);
	return (i);
}

static void	ft_putnbr_p(int n)
{
	long	i;
	char	c;

	i = n;
	if (i < 0)
	{
		i *= -1;
		write(1, "-", 1);
	}
	if (i > 9)
		ft_putnbr_p(i / 10);
	c = (i % 10) + '0';
	write(1, &c, 1);
}
