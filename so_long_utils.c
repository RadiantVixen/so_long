/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:45:47 by aatki             #+#    #+#             */
/*   Updated: 2022/12/21 22:40:17 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_long *l)
{
	free(l->p.s);
	exit(0);
}

void	putstr_error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
}

void	ft_error(char *s, int e)
{
	putstr_error("Error\n");
	putstr_error(s);
	exit(e);
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
