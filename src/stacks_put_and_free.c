/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_put_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 01:54:54 by mabu-are          #+#    #+#             */
/*   Updated: 2026/01/24 01:54:54 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_free_stacks(int exit_code, char *err_msg, t_stacks *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->target_a);
	free(s->rr);
	free(s->rrr);
	free(s);
	ft_printf("%s", err_msg);
	exit(exit_code);
}
