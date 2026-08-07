/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:25:27 by ntome             #+#    #+#             */
/*   Updated: 2026/08/08 00:03:08 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

void	print_help(void)
{
	printf("Usage: ./ft_queens [N] [--help]\n\n");
	printf("N: a number between 1 and 26\n");
	printf("help: display this help section\n");
	printf("\n\n");
	printf("The algorithm\n");
	printf("The algorithm behind the N-Queens problem is very simple;");
	printf("you need to understand the principle of backtracking (https://en.wikipedia.org/wiki/Backtracking).\n");
}

void	print_solution_code(state **board, int size)
{
	for (int line = 0; line < size; line++) {
		for (int col = 0; col < size; col++) {
			if (board[col][line] == QUEEN)
			{
				printf("%c%d", 'A' + line, (size - col));
				if (size >= 10)
					printf(";");
			}
		}
	}
	printf("\n");
}

#define RESET "\033[0m"
#define BLACK "\033[48;2;0;0;0m"
#define WHITE "\033[48;2;220;220;220m"
#define F_WHITE "\033[38;2;220;220;220m"
#define F_BLACK "\033[38;2;0;0;0m"

void	print_solution_board(state **board, int size)
{
	printf("%s  ╭", BLACK);
	for (int i = 0; i < size; i++)
		printf("───");
	printf("╮  %s\n", RESET);

	for (int i = 0; i < size; i++){
		printf("%s%2d│%s", BLACK, size - i, RESET);
		for (int j = 0; j < size; j++) {
			if ((i % 2 && j % 2) || (!(i % 2) && !(j % 2))) {
				printf("%s", WHITE);
				if (board[i][j] == QUEEN)
					printf("%s ♛ %s", F_BLACK, RESET);
				else
					printf("   ");
			}
			else {
				printf("%s", BLACK);
				if (board[i][j] == QUEEN)
					printf("%s ♛ %s", F_WHITE, RESET);
				else 
					printf("   ");
			}
		}
		printf("%s│  %s\n", BLACK, RESET);
	}

	printf("%s  ╰", BLACK);
	for (int i = 0; i < size; i++)
		printf("───");
	printf("╯  %s\n", RESET);
	printf("%s   ", BLACK);
	for (int i = 0; i < size; i++)
		printf(" %c ", 'A' + i);
	printf("   %s\n\n", RESET);
}

