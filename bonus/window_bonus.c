/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:40:44 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 19:45:41 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init(t_long *l)
{
	l->mlx = mlx_init();
	l->c = 0;
	l->anime = 0;
	l->dead_win = 0;
	l->moves = 0;
	l->window_width = l->p.len * 200;
	l->window_height = l->p.lines * 200;
}

int	initialize_long(t_long *l)
{
	init(l);
	l->window = mlx_new_window(l->mlx, l->window_width, l->window_height,
			"so_long game");
	l->img_width = l->window_width / l->p.len;
	l->img_height = l->window_height / l->p.lines;
	l->imgh = mlx_xpm_file_to_image(l->mlx, "././images/jinx.xpm",
			&l->img_width, &l->img_height);
	l->imgw = mlx_xpm_file_to_image(l->mlx, "././images/wall1.xpm",
			&l->img_width, &l->img_height);
	l->imgf = mlx_xpm_file_to_image(l->mlx, "././images/black.xpm",
			&l->img_width, &l->img_height);
	l->imgc = mlx_xpm_file_to_image(l->mlx, "././images/crystal1 black200.xpm",
			&l->img_width, &l->img_height);
	l->imgk = mlx_xpm_file_to_image(l->mlx, "././images/InventorsGrabBag.xpm",
			&l->img_width, &l->img_height);
	l->imgcup = mlx_xpm_file_to_image(l->mlx, "././images/justcat.xpm",
			&l->img_width, &l->img_height);
	l->imgrep = l->imgcup;
	l->imgrep2 = mlx_xpm_file_to_image(l->mlx, "././images/catlen.xpm",
			&l->img_width, &l->img_height);
	if (!l->imgh || !l->imgw || !l->imgf || !l->imgc || !l->imgk || !l->imgcup
		|| !l->imgrep2)
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
		if (l->p.s[i] == 'N')
			put_image(l, i, l->imgcup);
		i++;
	}
}

int	animation(t_long *l)
{
	void	*imgrep;

	if (l->anime == 2000)
	{
		l->imgcup = l->imgrep;
		affiche(l);
		after_hook(l);
	}
	else if (l->anime == 4000)
	{
		l->imgcup = l->imgrep2;
		affiche(l);
		after_hook(l);
		l->anime = 0;
	}
	l->anime++;
	if (l->dead_win == 1 || l->dead_win == 2)
		dead_win(l);
	return (0);
}
