/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:39:26 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 18:45:46 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	hook_in_pink(int i, int j, t_long *l)
{
	int	k;

	if ((l->p.s[j] == 'E') && (l->c == l->p.collect))
		l->dead_win = 2;
	if (l->p.s[j] != '1' && l->p.s[j] != 'E' && l->p.s[j] != 'N')
	{
		if (l->p.s[j] == 'C')
			l->c++;
		l->p.s[i] = '0';
		l->p.s[j] = 'P';
		l->moves++;
		affiche(l);
		after_hook(l);
	}
	l->anime = 2;
	enemy(l, 1);
	enemy(l, 0);
}

int	dead_win(t_long *l)
{
	void	*img;
	int		w;
	int		h;

	w = 300;
	h = 200;
	if (l->dead_win == 1 || l->dead_win == 2)
	{
		affiche(l);
		after_hook(l);
		if (l->dead_win == 1)
			img = mlx_xpm_file_to_image(l->mlx, "./images/you-are-dead.xpm", &w,
					&h);
		if (l->dead_win == 2)
			img = mlx_xpm_file_to_image(l->mlx, "./images/win.xpm", &w, &h);
		if (!img)
			ft_error("error in image GO", 1);
		h = (l->p.lines / 2) * 200;
		w = (l->p.len / 2) * 200;
		mlx_put_image_to_window(l->mlx, l->window, img, w, h);
		if (l->count_d == 100)
			exit(0);
		l->count_d++;
	}
	return (1);
}

void	after_hook(t_long *l)
{
	char	*s;

	s = ft_itoa(l->moves);
	mlx_string_put(l->mlx, l->window, 20, 10, 0xFFFFFF, "moves:");
	mlx_string_put(l->mlx, l->window, 102, 10, 0xFFFFFF, s);
	free(s);
}

int	new_position(int key, t_long *l)
{
	int	i;

	if (key == 53)
		exit(0);
	l->anime = 1;
	if (l->dead_win != 1 && l->dead_win != 2)
	{
		i = position(l->p.s, 'P');
		if (key == 126 || key == 13)
			hook_in_pink(i, i - l->p.len, l);
		if (key == 123 || key == 0)
			hook_in_pink(i, i - 1, l);
		if (key == 124 || key == 2)
			hook_in_pink(i, i + 1, l);
		if (key == 125 || key == 1)
			hook_in_pink(i, i + l->p.len, l);
	}
	return (1);
}
