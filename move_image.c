/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:39:26 by aatki             #+#    #+#             */
/*   Updated: 2022/12/27 16:53:13 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook_in_pink(int i, int j, t_long *l)
{
	if ((l->p.s[j] == 'E') && (l->c == l->p.collect))
		exit(0);
	if (l->p.s[j] != '1' && l->p.s[j] != 'E')
	{
		if (l->p.s[j] == 'C')
			l->c++;
		l->p.s[i] = '0';
		l->p.s[j] = 'P';
		affiche(l);
		l->moves++;
		write(1, "move: ", 6);
		put_nbr(l->moves);
		write(1, "\n", 1);
	}
}

int	new_position(int key, t_long *l)
{
	int	i;

	i = position(l->p.s);
	if (key == 53)
		exit(0);
	if (key == 126 || key == 13)
		hook_in_pink(i, i - l->p.len, l);
	if (key == 123 || key == 0)
		hook_in_pink(i, i - 1, l);
	if (key == 124 || key == 2)
		hook_in_pink(i, i + 1, l);
	if (key == 125 || key == 1)
		hook_in_pink(i, i + l->p.len, l);
	return (1);
}
