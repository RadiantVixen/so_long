/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:25:58 by aatki             #+#    #+#             */
/*   Updated: 2022/12/28 18:19:02 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct t_mapii
{
	int		len;
	int		lines;
	int		surounded_by_walls;
	int		pos;
	char	*s;
	int		collect;
	int		enemy;
	int		len_equal;
}			t_mapi;

typedef struct t_longg
{
	t_mapi	p;
	void	*mlx;
	void	*window;
	void	*imgh;
	void	*imgc;
	void	*imgw;
	void	*imgf;
	void	*imgk;
	void	*imgcup;
	void	*imgrep;
	void	*imgrep2;
	int		img_width;
	int		img_height;
	int		window_width;
	int		window_height;
	int		c;
	int		moves;
	int		dead_win;
	int		anime;
	int		count_d;
	int		pos;
}			t_long;

void		so_long(char *path);
char		*get_next_line(int fd);
size_t		ft_strlen(char *c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *src);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*check(char **s);

void		putstr_error(char *s, int d);
void		ft_error(char *s, int e);

t_mapi		initialize_mapi(int fd);
int			position(char *s, char c);
int			check_map(t_mapi d);
int			one(char *s);
int			number_of_thing(char *s, char c);
int			others(char *s);

int			check_zone(t_mapi d);
void		zone_coin(char *s, int i, int len, int lines);
void		zone_exit(char *s, int i, int len, int lines);

void		affiche(t_long *l);
int			initialize_long(t_long *l);
int			ft_path(char *s);
void		put_image(t_long *l, int i, void *img);

int			new_position(int key, t_long *l);
void		hook_in_pink(int i, int j, t_long *l);
int			ft_exit(t_long *l);
void		put_nbr(long n);
char		*ft_itoa(int n);
void		after_hook(t_long *l);
void		enemy(t_long *l, int n);
void		cupcake(t_long *l);
int			dead_win(t_long *l);
int			animation(t_long *l);

#endif
