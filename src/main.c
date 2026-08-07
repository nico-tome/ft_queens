/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:20:51 by ntome             #+#    #+#             */
/*   Updated: 2026/08/07 22:34:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queens.h"

int	main(int ac, char **av)
{
	int	size = 0;
	int	n = 0;

	if (ac < 2 || ac > 3)
	{
		dprintf(2, "ft_queens: wrong usage\n");
		dprintf(2, "Type <<ft_queens --help>> for more informations.\n");
		return (1);
	}
	
	if (parse_arg(ac, av))
		return (1);

	size = atoi(av[1]);
	n = solver(size);

	printf("solutions: %d\n", n);
	return (0);
}
