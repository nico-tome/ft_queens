/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <marvin@d42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:21:03 by ntome             #+#    #+#             */
/*   Updated: 2026/08/09 00:15:48 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

static bool	check_line(const char *line, int size)
{
	int	count = 0;

	for (int i = 0; line[i]; i++) {
		if (line[i] != ';' && line[i] < '0' && line[i] > '9')
			return (false);
		int	n = atoi(line + i);
		if (n > size)
			return (false);
		count++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
	}
	return (true);
}

static void	split_args(const char *line, int *queens, int size)
{
	int	i;
	int	value;

	i = 0;
	while (i < size)
	{
		value = 0;
		while (*line >= '0' && *line <= '9')
		{
			value = value * 10 + (*line - '0');
			++line;
		}

		queens[i++] = value;

		if (*line == ';')
			++line;
	}
}

static bool	check_board(char *line, int size)
{
	state	board[size * size];
	int		queens[size];
	int		error[size];
	bool	valid;

	split_args(line, queens, size);

	__builtin_memset(board, 0, sizeof(board));
	__builtin_memset(error, 0, sizeof(error));

	for (int col = 0; col < size; ++col)
		board[queens[col] * size + col] = QUEEN;

	valid = true;

	for (int col = 0; col < size; ++col)
	{
		for (int prev = 0; prev < col; ++prev)
		{
			if (queens[col] == queens[prev])
			{
				valid = false;
				error[col] = true;
			}

			if (__builtin_abs(queens[col] - queens[prev])
					== col - prev) {
				valid = false;
				error[col] = true;
			}
		}
	}

	if (valid)
		print_solution_board(board, size);
	else
		print_error_board(board, size, error);

	return (valid);
}

bool	checker(t_ctx ctx)
{
	FILE	*file;
	char	*line;
	size_t	capacity;
	bool	flag = true;

	file = fopen(ctx.path, "r");
	if (!file)
	{
		perror(ctx.path);
		return (false);
	}

	line = NULL;
	capacity = 0;

	while (getline(&line, &capacity, file) != -1) {
		if (!check_line(line, ctx.size)) {
			PRINT_ERROR(2, "Line is invalid.\n");
			PRINT_ERROR(2, line);
			PRINT_ERROR(2, "\n");
			return (false);
		}
		if (!check_board(line, ctx.size))
			flag = false;
	}

	free(line);
	fclose(file);
	return (flag);
}
