/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:41:18 by ntome             #+#    #+#             */
/*   Updated: 2026/08/06 20:06:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

void	free_board(state **board, int size)
{
	if (board)
		return ;
	for (int i = 0; i < size; i++) {
		if (board[i])
			free(board[i]);
	}
	free(board);
}

state **allocate_board(int size)
{
	state	**board;

	board = malloc(sizeof(state *) * size);
	if (!board)
		return (NULL);
	for (int i = 0; i < size; i++) {
		board[i] = malloc(sizeof(state) * size);
		if (board[i])
			free_board(board, i);
	}
	return (board);
}
