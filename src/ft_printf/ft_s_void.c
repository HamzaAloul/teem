/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_void.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:57:13 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/20 00:59:20 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(unsigned long c, const char *hex)
{
	char	p;

	if (c > 15)
		ft_print_hex(c / 16, hex);
	p = (hex[c % 16]);
	write(1, &p, 1);
}

static size_t	ft_s_len_hex(unsigned long c)
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

static size_t	ft_s_puthex_long(unsigned long c)
{
	const char	hex[] = {"0123456789abcdef"};

	ft_print_hex(c, hex);
	return (ft_s_len_hex(c));
}

size_t	ft_s_void(void *s)
{
	uintptr_t	address;
	size_t		i;

	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (uintptr_t)s;
	i = 2;
	write(1, "0x", 2);
	return (i + ft_s_puthex_long(address));
}
