/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queens.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:01:36 by ntome             #+#    #+#             */
/*   Updated: 2026/08/09 00:16:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEENS_H
# define FT_QUEENS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <fcntl.h>

# define BLACK  "\033[0;30m"
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN   "\033[0;36m"
# define WHITE  "\033[0;37m"
# define RESET  "\033[0m"

typedef enum e_state
{
	NONE,
	QUEEN
}	state;

typedef enum e_mode
{
	CHECK,
	SOLVE
}	mode;

typedef struct s_ctx
{
	mode		mode;
	const char	*path;
	int			size;
}	t_ctx;

#define PRINT_ERROR(fd, msg) (write(fd, msg, __builtin_strlen(msg)))

void	print_help(void);
void	print_solution_code(state *board, int size);
void	print_solution_board(state *board, int size);
void	print_error_board(state *board, int size, int *error);

int		solver(int size);
bool	checker(t_ctx ctx);

bool	parse_arg(int ac, char **av, t_ctx *ctx);

#endif
