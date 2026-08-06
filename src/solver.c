/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:13:20 by ntome             #+#    #+#             */
/*   Updated: 2026/08/06 21:33:06 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

static bool	is_safe(state **board, int line, int col, int size)
{
	int	col_left = col;
	int	col_right = col;

	for (; line >= 0; --line) {
		if (col_left >= 0 && board[line][col_left] == QUEEN)
			return (0);
		if (board[line][col] == QUEEN)
			return (0);
		if (col_right < size && board[line][col_right] == QUEEN)
			return (0);
		col_left -= 1;
		col_right += 1;
	}
	return (1);
}

static int	rec(state **board, int i, int size)
{
	int	nb_solutions;

	if (i == size)
	{
		print_solution_code(board, size);
		print_solution_board(board, size);
		return (1);
	}
	else
	{
		nb_solutions = 0;
		for (int j = 0; j < size; j++) {
			if (is_safe(board, i, j, size))
			{
				board[i][j] = QUEEN;
				nb_solutions += rec(board, i + 1, size);
				board[i][j] = NONE;
			}
		}
	}
	return (nb_solutions);
}

int	solver(int size)
{
	state	**board;
	int		s_c = 0;

	board = allocate_board(size);
	if (!board)
		return (0);

	for (int line = 0; line < size; line++) {
		for (int col = 0; col < size; col++) {
			board[line][col] = NONE;
		}
	}
	s_c = rec(board, 0, size);
	return (s_c);
}
