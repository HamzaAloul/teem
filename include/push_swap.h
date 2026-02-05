/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:02:23 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/05 20:15:45 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_INPUT 2
# define EXIT_DUPLICATES 3

# include <stdlib.h> // exit, malloc
# include <stdbool.h> // bool
# include <limits.h> // INT_MAX, etc.
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"

/* ************************************************************************** */
/*                           PART 1 - STRUCT                                  */
/* ************************************************************************** */
typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	size_t	size_a;
	size_t	size_b;
	size_t	*target_a;
	size_t	target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_stacks;

/* ************************************************************************** */
/*                           PART 2 - PROGRAM                                 */
/* ************************************************************************** */

// push_swap_main.c
int		main(int argc, char **argv);
double	compute_disorder(t_stacks *stacks);
int	len_arr(char **argv, int argc);
/* ************************************************************************** */
/*                        ERROR HANDLING & INPUT                              */
/* ************************************************************************** */
void	duplicate_error(int *n, int size);
void	not_int_error(char **argv);

/* ************************************************************************** */
/*                        	  MOVES		                              */
/* ************************************************************************** */

// moves_a.c
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// moves_b.c
void	sb(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);

// moves_ab.c
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *stacks);
void	check_arg_put_stacks(int argc, char **argv, t_stacks *stacks);
#endif
