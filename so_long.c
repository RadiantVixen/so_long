/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:37:51 by aatki             #+#    #+#             */
/*   Updated: 2022/12/21 22:44:26 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *path)
{
	int		fd;
	t_long	l;

	fd = open(path, O_RDONLY);
	l.p = initialize_mapi(fd);
	check_map(l.p);
	initialize_long(&l);
	affiche(&l);
	mlx_key_hook(l.window, new_position, &l);
	mlx_hook(l.window, 17, 0, ft_exit, &l);
	mlx_loop(l.mlx);
}

int	main(int argc, char **v)
{
	if (argc == 2)
	{
		so_long(v[1]);
	}
	return (0);
}
