/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:39:26 by aatki             #+#    #+#             */
/*   Updated: 2022/12/21 22:13:44 by aatki            ###   ########.fr       */
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
	}
}

int	new_position(int key, t_long *l)
{
	int	i;

	i = position(l->p.s);
	if (key == 53)
		exit(0);
	if (key == 126)
		hook_in_pink(i, i - l->p.len, l);
	if (key == 123)
		hook_in_pink(i, i - 1, l);
	if (key == 124)
		hook_in_pink(i, i + 1, l);
	if (key == 125)
		hook_in_pink(i, i + l->p.len, l);
	return (1);
}
