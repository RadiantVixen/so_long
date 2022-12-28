/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:33:44 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 18:41:58 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_path(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			break ;
		i++;
	}
	if (s[i + 1] == 'b' && s[i + 2] == 'e')
		if (s[i + 3] == 'r' && s[i + 4] == '\0')
			return (1);
	return (0);
}

int	number_of_thing(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	others(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != 'P' && s[i] != 'C' && s[i] != 'E' && s[i] != '0'
			&& s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
