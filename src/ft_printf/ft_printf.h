/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:36:53 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/18 17:10:39 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

/* ************************************************************************** */
/*                           MAIN PART - PRINTF		                      */
/* ************************************************************************** */
int		ft_printf(const char *s, ...);

/* ************************************************************************** */
/*                         SECEND PART - HELPER FUN                           */
/* ************************************************************************** */
size_t	ft_s_putchar(int c);
size_t	ft_s_putnbr(int n);
size_t	ft_s_string(char const *s);
size_t	ft_s_void(void *s);
size_t	ft_s_putnbr_u(unsigned int i);
size_t	ft_s_puthex(unsigned int c, char format);

#endif
