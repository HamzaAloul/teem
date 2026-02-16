/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:02:23 by mabu-are          #+#    #+#             */
/*   Updated: 2026/02/16 23:32:41 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_INPUT 2
# define EXIT_DUPLICATES 3

# include <fcntl.h>
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
	double	cost;
}	t_stacks;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	char	*strategy;
	double	disorder;
}	t_bench;

/* ************************************************************************** */
/*                           PART 2 - PROGRAM                                 */
/* ************************************************************************** */

// push_swap_main.c
t_stacks	*fill_stack_a(char **argv, int argc, int i, t_bench *b);
double		compute_disorder(t_stacks *stacks);
void		adaptive(int argc, char **argv, t_stacks *stacks, t_bench *b);
void		test_if_sort(t_stacks *stacks, char **argv, t_bench *b);
void		flags(int argc, char **argv);
void		selection_sort(t_stacks *s, char **argv, t_bench *b);
void		short_sort(t_stacks *s, char **argv, t_bench *b);
void		refill(t_stacks *s);
void		bench(char **argv, t_bench *b);
void		chunke_sort(t_stacks *stacks, int min, char **argv, t_bench *b);
void		radix(t_stacks *s, char **argv, t_bench *b);
int			len_arr(char **argv, int argc, int i);
int			main(int argc, char **argv);
/* ************************************************************************** */
/*                        ERROR HANDLING & INPUT                              */
/* ************************************************************************** */

void		duplicate_error(t_stacks *stacks);
void		not_int_error(char **argv, int i);
void		exit_free_stacks(int exit_code, char *err_msg, t_stacks *stacks);

/* ************************************************************************** */
/*                        	  MOVES		                              */
/* ************************************************************************** */

// moves_a.c
void		sa(t_stacks *stacks, t_bench *b);
void		pa(t_stacks *stacks, t_bench *b);
void		ra(t_stacks *stacks, t_bench *b);
void		rra(t_stacks *stacks, t_bench *b);

// moves_b.c
void		sb(t_stacks *stacks, t_bench *b);
void		pb(t_stacks *stacks, t_bench *b);
void		rb(t_stacks *stacks, t_bench *b);
void		rrb(t_stacks *stacks, t_bench *b);

// moves_ab.c
void		ss(t_stacks *stacks, t_bench *b);
void		rr(t_stacks *stacks, t_bench *b);
void		rrr(t_stacks *stacks, t_bench *b);

void		check_arg_put_stacks(int argc, char **argv, t_stacks *stacks);
#endif
