/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuss_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:29:09 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 18:45:16 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	compteur(long *nb, int *sign)
{
	int		cmpt;
	long	i;

	cmpt = 0;
	i = *nb;
	if (*nb < 0)
	{
		*sign = -1;
		*nb *= -1;
	}
	else
		*sign = 1;
	if (i < 0)
	{
		i = i * (-1);
		cmpt++;
	}
	while (i >= 1)
	{
		i = i / 10;
		cmpt++;
	}
	return (cmpt);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		cmpt;
	long	i;
	int		sign;
	long	nb;

	nb = n;
	i = n;
	cmpt = compteur(&nb, &sign);
	if (i == 0)
		return (ft_strdup("0"));
	itoa = malloc(cmpt + 1);
	if (!itoa)
		return (NULL);
	i = cmpt;
	itoa[i--] = '\0';
	while (nb)
	{
		itoa[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	if (sign == -1)
		itoa[0] = '-';
	return (itoa);
}

// void	cupcake(t_long *l)
// {
// 	static int	alia;

// 	if (!l->p.enemy)
// 		return ;
// 	if (alia == 0 || alia >= l->p.len * l->p.lines)
// 		alia = 1;
// 	while (alia < l->p.len * l->p.lines)
// 	{
// 		if (l->p.s[alia] != '1' && l->p.s[alia] != 'E' && l->p.s[alia] != 'C'
// 			&& l->p.s[alia] != 'P')
// 		{
// 			l->p.s[position(l->p.s, 'N')] = '0';
// 			l->p.s[alia] = 'N';
// 			alia += 1;
// 			break ;
// 		}
// 		affiche(l);
// 		after_hook(l);
// 		alia += 1;
// 	}
// }

void	just_func(t_long *l, int t)
{
	int	i;

	i = 0;
	while (t && l->p.s[i])
	{
		if (t && l->p.s[i] == '0')
		{
			l->p.s[t] = '0';
			l->p.s[i] = 'N';
			break ;
		}
		i++;
	}
	affiche(l);
	after_hook(l);
}

void	cupcake(t_long *l)
{
	int	i;
	int	t;

	i = 0;
	if (!l->p.enemy)
		return ;
	t = 0;
	while (l->p.s[i])
	{
		if (l->p.s[i] == 'N')
			t = i;
		if (l->p.s[t] == 'N' && l->p.s[i + 1] == '0')
		{
			l->p.s[t] = '0';
			l->p.s[i + 1] = 'N';
			t = 0;
			i++;
		}
		if (l->p.s[i])
			i++;
	}
	just_func(l, t);
}

void	enemy(t_long *l, int n)
{
	int	i;
	int	k;

	if (!l->p.enemy)
		return ;
	i = position(l->p.s, 'P');
	k = 0;
	while (l->p.s[k])
	{
		if (l->p.s[k] == 'N')
		{
			if (i == k + 1 || i == k - 1 || i == k + l->p.len || i == k
				- l->p.len)
				l->dead_win = 1;
		}
		k++;
	}
	if (n && l->dead_win != 1)
		cupcake(l);
}
