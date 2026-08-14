/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:13:20 by ntome             #+#    #+#             */
/*   Updated: 2026/08/15 00:46:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>

static int	rec(state *board, int line, int size, uint64_t columns, uint64_t diag_left, uint64_t diag_right, uint64_t mask)
{
	uint64_t	available;
	uint64_t	bit;
	int			col;
	int			nb_solutions;

	if (line == size)
	{
		print_solution_code(board, size);
		print_solution_board(board, size);
		return (1);
	}

	available = mask & ~(columns | diag_left | diag_right);
	nb_solutions = 0;

	while (available)
	{
		bit = available & -available;
		available ^= bit;

		col = __builtin_ctzll(bit);
		board[line * size + col] = QUEEN;

		nb_solutions += rec(board, line + 1, size, columns | bit, (diag_left | bit) << 1, (diag_right | bit) >> 1, mask);

		board[line * size + col] = NONE;
	}

	return (nb_solutions);
}

int	solver(int size)
{
	state		board[size * size];
	uint64_t	mask;
	int			solutions;

	if (size <= 0 || size > 12)
		return (0);
	
	mask = (1ULL << size) - 1;

	memset(board, 0, sizeof(board));

	solutions = rec(board, 0, size, 0, 0, 0, mask);

	return (solutions);
}
