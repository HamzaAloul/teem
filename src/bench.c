/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:19:49 by halalul           #+#    #+#             */
/*   Updated: 2026/02/17 16:37:22 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	line_2(char **argv, t_bench *b)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(b->strategy, 2);
	if (ft_strncmp(argv[2], "--simple", 8) == 0)
		ft_putstr_fd(" / O(n^2)", 2);
	else if (ft_strncmp(argv[2], "--medium", 8) == 0)
		ft_putstr_fd(" / O(n*√n)", 2);
	else if (ft_strncmp(argv[2], "--complex", 9) == 0)
		ft_putstr_fd(" / O(n*(log n))", 2);
	else if (b->disorder < 0.2)
		ft_putstr_fd(" / O(n)", 2);
	else if (b->disorder < 0.5)
		ft_putstr_fd(" / O(n*√n)", 2);
	else if (b->disorder >= 0.5)
		ft_putstr_fd(" / O(n*(log n))", 2);
	ft_putstr_fd("\n", 2);
}

static void	line_1_2_3(char **argv, t_bench *b)
{
	int	d;

	d = b->disorder * 10000;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(d / 100, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(d % 100, 2);
	ft_putstr_fd("%", 2);
	ft_putstr_fd("\n", 2);
	line_2(argv, b);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(b->total, 2);
	ft_putstr_fd("\n", 2);
}

static void	line_4_5(t_bench *b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench(char **argv, t_bench *b)
{
	if (ft_strncmp(argv[1], "--bench", 7) != 0)
	{
		free(b);
		return ;
	}
	line_1_2_3(argv, b);
	line_4_5(b);
	free(b);
}
