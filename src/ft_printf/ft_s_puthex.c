/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_puthex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:57:13 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/18 17:13:38 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(unsigned int c, const char *hex, int a)
{
	char	p;

	if (c > 15)
		ft_print_hex(c / 16, hex, a);
	if (c % 16 > 9)
		p = (hex[c % 16]) - a;
	else
		p = (hex[c % 16]);
	write(1, &p, 1);
}

static size_t	ft_s_len_hex(unsigned int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		i++;
	while (c != 0)
	{
		c = c / 16;
		i++;
	}
	return (i);
}

size_t	ft_s_puthex(unsigned int c, char format)
{
	const char	hex[] = {"0123456789abcdef"};
	int			a;

	if (format == 'x')
		a = 0;
	else
		a = 32;
	ft_print_hex(c, hex, a);
	return (ft_s_len_hex(c));
}
