/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:20:51 by ntome             #+#    #+#             */
/*   Updated: 2026/08/08 23:13:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

int	main(int ac, char **av)
{
	t_ctx	ctx = { 0 };


	if (ac < 2 || ac > 4)
	{
		PRINT_ERROR(2, "ft_queens: wrong usage\n");
		PRINT_ERROR(2, "Type <<ft_queens --help>> for more informations.\n");
		return (1);
	}
	
	if (parse_arg(ac, av, &ctx))
		return (1);

	if (ctx.mode == CHECK) {
		int	n = checker(ctx);
		return (n);
	} else if (ctx.mode == SOLVE) {
		int	n = solver(ctx.size);
		printf("Solutions: %s%d%s\n", GREEN, n, RESET);
		return (0);
	}
	return (0);
}
