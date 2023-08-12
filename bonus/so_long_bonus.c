/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:37:51 by aatki             #+#    #+#             */
/*   Updated: 2023/08/12 01:10:09 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long(char *path)
{
	int		fd;
	t_long	l;

	if (!ft_path(path))
		ft_error("probleme in extention", 13);
	fd = open(path, O_RDONLY);
	l.p = initialize_mapi(fd);
	check_map(l.p);
	initialize_long(&l);
	affiche(&l);
	enemy(&l, 0);
	mlx_key_hook(l.window, new_position, &l);
	mlx_loop_hook(l.mlx, dead_win, &l);
	mlx_loop_hook(l.mlx, animation, &l);
	mlx_hook(l.window, 17, 0, ft_exit, &l);
	mlx_loop(l.mlx);
}

int	main(int c, char **v)
{
	if (c == 2)
		so_long(v[1]);
	return (1);
}
