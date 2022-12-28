/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:05:50 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 16:25:25 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	one(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	position(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	initialize(t_mapi *d, char *tmp)
{
	d->lines = 0;
	d->surounded_by_walls = 1;
	d->len_equal = 1;
	if (!tmp)
		ft_error("map vide or Path fauls", 7);
	d->len = ft_strlen(tmp);
	d->s = ft_strdup("");
	if (!one(tmp))
		d->surounded_by_walls = 0;
}

t_mapi	initialize_mapi(int fd)
{
	char	*tmp;
	t_mapi	d;

	tmp = get_next_line(fd);
	initialize(&d, tmp);
	while (tmp)
	{
		d.s = ft_strjoin(d.s, tmp);
		if (ft_strlen(tmp) != (size_t)d.len)
			d.len_equal = 0;
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && (*tmp != '1' || *(tmp + d.len - 1) != '1'))
			d.surounded_by_walls = 0;
		d.lines++;
	}
	if (!one(d.s + (d.lines - 1) * d.len))
		d.surounded_by_walls = 0;
	d.pos = position(d.s, 'P');
	d.collect = number_of_thing(d.s, 'C');
	d.enemy = number_of_thing(d.s, 'N');
	return (d);
}

int	check_map(t_mapi d)
{
	if (number_of_thing(d.s, 'P') != 1)
		ft_error("number of player not valid", 1);
	if (number_of_thing(d.s, 'E') != 1)
		ft_error("number of exit not valid", 2);
	if (number_of_thing(d.s, 'C') < 1)
		ft_error("there's no collects", 3);
	if (d.surounded_by_walls != 1)
		ft_error("not surrounded by wallls", 4);
	if (d.len_equal != 1)
		ft_error("the lines not equal", 5);
	if (others(d.s))
		ft_error("there is an other carracter", 6);
	check_zone(d);
	return (1);
}
