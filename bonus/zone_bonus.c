/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:11 by aatki             #+#    #+#             */
/*   Updated: 2022/12/27 17:24:31 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	zone_coin(char *s, int i, int len, int lines)
{
	if (i < 0 || i > len * lines - 1)
		return ;
	if (s[i] != 'C' && s[i] != '0' && s[i] != 'P' && s[i] != 'N')
		return ;
	s[i] = 'h';
	zone_coin(s, i + 1, len, lines);
	zone_coin(s, i - 1, len, lines);
	zone_coin(s, i + len, len, lines);
	zone_coin(s, i - len, len, lines);
}

void	zone_exit(char *s, int i, int len, int lines)
{
	if (i < 0 || i > len * lines - 1)
		return ;
	if (s[i] != 'h' && s[i] != '0' && s[i] != 'E')
		return ;
	s[i] = 'f';
	zone_exit(s, i + 1, len, lines);
	zone_exit(s, i - 1, len, lines);
	zone_exit(s, i + len, len, lines);
	zone_exit(s, i - len, len, lines);
}

int	check_zone(t_mapi d)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strdup(d.s);
	zone_coin(s, d.pos, d.len, d.lines);
	if (number_of_thing(s, 'C') > 0)
	{
		free(s);
		ft_error("can't collect all coins", 9);
	}
	zone_exit(s, d.pos, d.len, d.lines);
	if (number_of_thing(s, 'E') > 0)
	{
		free(s);
		ft_error("can't exit", 10);
	}
	free(s);
	return (1);
}
