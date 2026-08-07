/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queens.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:01:36 by ntome             #+#    #+#             */
/*   Updated: 2026/08/07 23:54:34 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEENS_H
# define FT_QUEENS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

typedef enum e_state
{
	NONE,
	QUEEN
}	state;

void	print_help(void);
void	print_solution_code(state **board, int size);
void	print_solution_board(state **board, int size);

void	free_board(state **board, int size);
state	**allocate_board(int size);

int		solver(int size);

bool	parse_arg(int ac, char **av);

#endif
