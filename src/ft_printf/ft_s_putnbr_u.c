/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_putnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 23:26:38 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/17 20:16:50 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_un(unsigned int un)
{
	char	c;

	if (un > 9)
		print_un(un / 10);
	c = (un % 10) + '0';
	write (1, &c, 1);
}

static size_t	len_u(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_s_putnbr_u(unsigned int i)
{
	print_un(i);
	return (len_u(i));
}
