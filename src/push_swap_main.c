/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   +:+      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:12:17 by mabu-are          #+#    #+#             */
/*   Updated: 2026/01/23 20:12:17 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "libft/libft.h"

int	main(int argc, char argv[][])
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (0);
	check_arg_put_stacks(argc, argv, stacks);
}
