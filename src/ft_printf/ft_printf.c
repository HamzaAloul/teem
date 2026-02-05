/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:49:24 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/18 16:59:12 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen_p(const char *s);

static size_t	format(const char c, va_list *ap);

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	a;
	va_list	ap;
	size_t	end;

	va_start(ap, s);
	i = 0;
	a = 0;
	end = ft_strlen_p(s);
	while (i < end)
	{
		if (s[i] == '%' && s[i + 1] != '%')
			a += format(s[++i], &ap);
		else
		{
			if (s[i] == '%' && s[i + 1] == '%')
				i++;
			a += ft_s_putchar(s[i]);
		}
		i++;
	}
	va_end(ap);
	return ((int)a);
}

static size_t	format(const char c, va_list *ap)
{
	size_t	i;

	i = 0;
	if (c == 'c')
		i += ft_s_putchar(va_arg(*ap, int));
	else if (c == 's')
		i += ft_s_string(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		i += ft_s_putnbr(va_arg(*ap, int));
	return (i);
}

static size_t	ft_strlen_p(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
