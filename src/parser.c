/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <marvin@d42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:34:34 by ntome             #+#    #+#             */
/*   Updated: 2026/08/08 22:59:08 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

static bool	is_num(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (false);
	}
	return (true);
}

static bool	parse_check(int ac, char **av)
{
	if (!strcmp(av[1], "--check"))
	{
		if (ac != 4) {
			PRINT_ERROR(2, "ft_queens: missing 1 argument.\n");
			PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
			return (true);
		}
		int	fd = open(av[2], O_RDONLY);
		if (fd == -1) {
			PRINT_ERROR(2, "ft_queens: path given is not valid.\n");
			PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
			return (true);
		}
		close(fd);
		if (!is_num(av[3])) {
			PRINT_ERROR(2, "ft_queens: argument N is not a number.\n");
			PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
			return (true);
		}
		int	n = atoi(av[3]);
		if (n < 1 || n > 26) {
			PRINT_ERROR(2, "ft_queens: number N not between 1 and 26.\n");
			PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
			return (true);
		}
	}
	return (false);
}

static bool	parse_solve(int ac, char **av)
{
	if (ac < 3) {
		PRINT_ERROR(2, "ft_queens: missing 1 argumnent.\n");
		PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
		return (true);
	}
	int	n = atoi(av[2]);
	if (n < 1 || n > 12) {
		PRINT_ERROR(2, "ft_queens: argument N not beetween 1 and 12.\n");
		PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
		return (true);
	}
	return (false);
}

bool	parse_arg(int ac, char **av, t_ctx *ctx)
{
	if (!strcmp(av[1], "--check")) {
		if (parse_check(ac, av))
			return (true);
		ctx->mode = CHECK;
		ctx->path = av[2];
		ctx->size = atoi(av[3]);
		return (false);
	} else if (!strcmp(av[1], "--solve")) {
		if (parse_solve(ac, av))
			return (true);
		ctx->mode = SOLVE;
		ctx->path = NULL;
		ctx->size = atoi(av[2]);
		return (false);
	} else if (!strcmp(av[1], "--help")) {
		print_help();
		return (true);
	} else {
		PRINT_ERROR(2, "ft_queens: invalid arg.\n");
		PRINT_ERROR(2, "Type << ft_queens --help >> for more information.\n");
		return (true);
	}
}
