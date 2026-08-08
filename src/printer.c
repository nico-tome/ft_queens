/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:25:27 by ntome             #+#    #+#             */
/*   Updated: 2026/08/09 00:17:46 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

void	print_help(void)
{
	printf("Usage: ./ft_queens %sACTION%s %s[OPT...]%s\n\n",
			GREEN, RESET, YELLOW, RESET);
	printf("%sACTION%s:\n", GREEN, RESET);
	printf(" %s--check%s %sPATH%s %sN%s\tCheck if the solutions stored in a file %sPATH%s are true or not.\n",
			GREEN, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET);
	printf(" %s--find%s  %sN%s\tFind all the solutions for a board of size %sN%s.\n",
			GREEN, RESET, YELLOW, RESET, YELLOW, RESET);
	printf(" %s--help%s\t\tShow this help.\n", GREEN, RESET);
	printf("\n%sOPT%s:\n", YELLOW, RESET);
	printf(" %sPATH%s:\t\tWith %s--check%s, the path to the file where the solutions you want to check are stored.\n",
			YELLOW, RESET, GREEN, RESET);
	printf(" %sN%s:\t\tWith %s--check%s and %s--find%s, represent the size of the board. Must be a number between 1 and 12\n",
			YELLOW, RESET, GREEN, RESET, GREEN, RESET);
	printf("\n\n");
	printf("The algorithm\n");
	printf("The algorithm behind the N-Queens problem is very simple;");
	printf("you need to understand the principle of backtracking ([https://en.wikipedia.org/wiki/Backtracking).\n](https://en.wikipedia.org/wiki/Backtracking\\).\n)");
}

#define B_BLACK "\033[48;2;0;0;0m"
#define B_WHITE "\033[48;2;220;220;220m"
#define F_WHITE "\033[38;2;220;220;220m"
#define F_BLACK "\033[38;2;0;0;0m"
#define F_RED   "\033[38;2;255;0;0m"
#define RESET   "\033[0m"

#define CELL_EMPTY_BLACK  B_BLACK "   " RESET
#define CELL_EMPTY_WHITE  B_WHITE "   " RESET

#define CELL_QUEEN_BLACK  B_BLACK F_WHITE " ♛ " RESET
#define CELL_QUEEN_WHITE  B_WHITE F_BLACK " ♛ " RESET

#define CELL_ERROR_BLACK  B_BLACK F_RED " ♛ " RESET
#define CELL_ERROR_WHITE  B_WHITE F_RED " ♛ " RESET

static size_t	append_str(char *buf, size_t pos, const char *str)
{
	while (*str)
		buf[pos++] = *str++;
	return (pos);
}

static size_t	append_number(char *buf, size_t pos, int n)
{
	if (n < 10)
		buf[pos++] = ' ';
	if (n >= 10)
		buf[pos++] = '0' + n / 10;
	buf[pos++] = '0' + n % 10;
	return (pos);
}

void	print_solution_code(state *board, int size)
{
	char	buf[(size_t)size * 4 + 2];
	size_t	pos;

	pos = 0;
	for (int col = 0; col < size; ++col)
	{
		for (int row = 0; row < size; ++row)
		{
			if (board[row * size + col] == QUEEN)
			{
				buf[pos++] = 'A' + col;
				if (size >= 10)
				{
					int rank = size - row;

					if (rank >= 10)
						buf[pos++] = '0' + rank / 10;
					buf[pos++] = '0' + rank % 10;
					buf[pos++] = ';';
				}
				else
					buf[pos++] = '0' + size - row;
				break;
			}
		}
	}
	buf[pos++] = '\n';
	(void)write(STDOUT_FILENO, buf, pos);
}

void	print_solution_board(state *board, int size)
{
	size_t	pos;
	char	buf[128 + (size_t)size * size * 48];

	pos = 0;
	pos = append_str(buf, pos, B_BLACK "  ╭");

	for (int i = 0; i < size; ++i)
		pos = append_str(buf, pos, "───");

	pos = append_str(buf, pos, "╮  " RESET "\n");

	for (int row = 0; row < size; ++row)
	{
		pos = append_str(buf, pos, B_BLACK);
		pos = append_number(buf, pos, size - row);
		pos = append_str(buf, pos, "│" RESET);

		state *line = board + row * size;

		for (int col = 0; col < size; ++col)
		{
			bool	white = ((row + col) & 1) == 0;

			if (line[col] == QUEEN)
			{
				if (white)
					pos = append_str(buf, pos, CELL_QUEEN_WHITE);
				else
					pos = append_str(buf, pos, CELL_QUEEN_BLACK);
			}
			else
			{
				if (white)
					pos = append_str(buf, pos, CELL_EMPTY_WHITE);
				else
					pos = append_str(buf, pos, CELL_EMPTY_BLACK);
			}
		}

		pos = append_str(buf, pos, B_BLACK "│  " RESET "\n");
	}

	pos = append_str(buf, pos, B_BLACK "  ╰");

	for (int i = 0; i < size; ++i)
		pos = append_str(buf, pos, "───");

	pos = append_str(buf, pos, "╯  " RESET "\n");
	pos = append_str(buf, pos, B_BLACK "   ");

	for (int col = 0; col < size; ++col)
	{
		buf[pos++] = ' ';
		buf[pos++] = 'A' + col;
		buf[pos++] = ' ';
	}

	pos = append_str(buf, pos, "   " RESET "\n\n");

	(void)write(STDOUT_FILENO, buf, pos);
}

void	print_error_board(state *board, int size, int *error)
{
	size_t	pos;
	char	buf[128 + (size_t)size * size * 48];

	pos = 0;

	pos = append_str(buf, pos, B_BLACK "  ╭");

	for (int i = 0; i < size; ++i)
		pos = append_str(buf, pos, "───");

	pos = append_str(buf, pos, "╮  " RESET "\n");

	for (int row = 0; row < size; ++row)
	{
		pos = append_str(buf, pos, B_BLACK);
		pos = append_number(buf, pos, size - row);
		pos = append_str(buf, pos, "│" RESET);

		state *line = board + row * size;

		for (int col = 0; col < size; ++col)
		{
			bool	white;
			bool	is_error;

			white = ((row + col) & 1) == 0;
			is_error = (line[col] == QUEEN && error[col]);

			if (is_error)
			{
				if (white)
					pos = append_str(buf, pos, CELL_ERROR_WHITE);
				else
					pos = append_str(buf, pos, CELL_ERROR_BLACK);
			}
			else if (line[col] == QUEEN)
			{
				if (white)
					pos = append_str(buf, pos, CELL_QUEEN_WHITE);
				else
					pos = append_str(buf, pos, CELL_QUEEN_BLACK);
			}
			else
			{
				if (white)
					pos = append_str(buf, pos, CELL_EMPTY_WHITE);
				else
					pos = append_str(buf, pos, CELL_EMPTY_BLACK);
			}
		}

		pos = append_str(buf, pos, B_BLACK "│  " RESET "\n");
	}

	pos = append_str(buf, pos, B_BLACK "  ╰");

	for (int i = 0; i < size; ++i)
		pos = append_str(buf, pos, "───");

	pos = append_str(buf, pos, "╯  " RESET "\n");
	pos = append_str(buf, pos, B_BLACK "   ");

	for (int col = 0; col < size; ++col)
	{
		buf[pos++] = ' ';
		buf[pos++] = 'A' + col;
		buf[pos++] = ' ';
	}

	pos = append_str(buf, pos, "   " RESET "\n\n");

	(void)write(STDOUT_FILENO, buf, pos);
}
