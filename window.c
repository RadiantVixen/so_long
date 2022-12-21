/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:40:44 by aatki             #+#    #+#             */
/*   Updated: 2022/12/21 22:56:15 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_long(t_long *l)
{
	l->mlx = mlx_init();
	l->c = 0;
	l->window_width = l->p.len * 100;
	l->window_height = l->p.lines * 100;
	l->window = mlx_new_window(l->mlx, l->window_width, l->window_height,
			"so_long game");
	l->img_width = l->window_width / l->p.len;
	l->img_height = l->window_height / l->p.lines;
	l->imgh = mlx_xpm_file_to_image(l->mlx, "./images/hacker.xpm",
			&l->img_width, &l->img_height);
	l->imgw = mlx_xpm_file_to_image(l->mlx, "./images/wall.xpm", &l->img_width,
			&l->img_height);
	l->imgf = mlx_xpm_file_to_image(l->mlx, "./images/floor.xpm", &l->img_width,
			&l->img_height);
	l->imgc = mlx_xpm_file_to_image(l->mlx, "./images/coin.xpm", &l->img_width,
			&l->img_height);
	l->imgk = mlx_xpm_file_to_image(l->mlx, "./images/key.xpm", &l->img_width,
			&l->img_height);
	if (!l->imgh || !l->imgw || !l->imgf || !l->imgc || !l->imgk)
		ft_error("errore in images", 11);
	return (0);
}

void	put_image(t_long *l, int i, void *img)
{
	int	w;
	int	h;
	int	k;

	k = l->p.len;
	w = (i % k) * (l->window_width / k);
	h = (i / k) * (l->window_height / l->p.lines);
	mlx_put_image_to_window(l->mlx, l->window, img, w, h);
}

void	affiche(t_long *l)
{
	int	i;

	i = 0;
	while (l->p.s[i])
	{
		if (l->p.s[i] == 'P')
			put_image(l, i, l->imgh);
		if (l->p.s[i] == '1')
			put_image(l, i, l->imgw);
		if (l->p.s[i] == '0')
			put_image(l, i, l->imgf);
		if (l->p.s[i] == 'C')
			put_image(l, i, l->imgc);
		if (l->p.s[i] == 'E')
			put_image(l, i, l->imgk);
		i++;
	}
}
