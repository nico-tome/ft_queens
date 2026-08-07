/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <marvin@d42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:34:34 by ntome             #+#    #+#             */
/*   Updated: 2026/08/07 23:54:14 by ntome            ###   ########.fr       */
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

bool	parse_arg(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		if (!strcmp(av[i], "--help"))
		{
			print_help();
			return (true);
		}
		if (!is_num(av[i]))
		{
			dprintf(2, "ft_queens: wrong argument '%s', is not a number.\n", av[i]);
			dprintf(2, "Type << ft_queens --help >> for more informations.\n");
			return (true);
		}
		int	c = atoi(av[i]);
		if (c < 0 || c > 26)
		{
			dprintf(2, "ft_queens: arg '%d' not beetween 1 and 26.\n", c);
			dprintf(2, "Type << ft_queens --help >> for more informations.\n");
			return (true);
		}
	}
	return (false);
}
