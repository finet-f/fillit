/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detection.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 15:00:33 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 09:58:56 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

s_tetri	new_piece(s_tetri info, int alpha, char *form)
{
	s_tetri	next;

	next.previous = &info;
	next.alpha = alpha;
	next.forme = form;
	next.next = NULL;
	return (next);
}

int		start_finder(s_tetri info, int alpha)
{
	int		start;
	int		y;

	start = 4;
	y = 0;
	while (info.forme[y] != '\0')
	{
		if (info.forme[y] == alpha && y % 4 < start)
			start = y % 4;
		y++;
	}
	y = 0;
	while (info.forme[y] != alpha)
	{
		y++;
	}
	while (y % 4 != start)
		y--;
	return (y);
}

int		get_width(s_tetri info, int alpha)
{
	int		y;
	int		width;
	int		tmpmax;

	tmpmax = 0;
	width = 0;
	y = 0;
	while (info.forme[y] != '\0')
	{
		if (info.forme[y] == alpha && y % 4 > tmpmax)
			tmpmax = y % 4;
		if (tmpmax - ((info.start % 4) - 1) > width)
			width = tmpmax - ((info.start % 4) - 1);
		y++;
	}
	return (width);
}

int		get_height(s_tetri info, int alpha)
{
	int		height;
	int		y;
	int		tmp;

	height = 0;
	y = 0;
	tmp = 0;
	while (y < 16)
	{
		if (info.forme[y] == alpha)
		{
			tmp++;
			y++;
			while (y % 4 != 0)
				y++;
		}
		else
			y++;
		if (tmp > height)
			height = tmp;
	}
	return (height);
}

char	**map_maker(int size)
{
	char	**maptmp;
	int		i;
	char	*s;
	int		k;

	k = 0;
	i = 0;
	if (!(maptmp = malloc(sizeof(char**) * size + 1)))
		return (NULL);
	maptmp[size] = 0;
	while (i < size)
	{
		s = ft_strnew(size);
		maptmp[i] = ft_memset(s, '.', size);
		i++;
	}
	return (maptmp);
}

int		formalloc(char **map, s_tab tab, s_tetri info)
{
	int		co[5];
	int		start;

	co[0] = tab.i;
	co[1] = tab.j;
	co[2] = info.start;
	start = info.start;
	while (co[0] != tab.i + info.height && co[0] < tab.size && co[2] < 16)
	{
		co[1] = tab.j;
		while (co[1] != tab.j + info.width && co[1] < tab.size && co[2] < 16)
			if (map[co[0]][co[1]++] != '.' && info.forme[start] == info.alpha)
				return (0);
			else if (++start == co[2] + info.width)
			{
				co[2] = co[2] + 4;
				start = co[2];
			}
		co[0]++;
	}
	if (co[1] == tab.j + info.width && co[0] == tab.i + info.height)
		return (1);
	else if (co[1] >= tab.size && co[0] >= tab.size)
		return (2);
	return (0);
}

char	**del_alpha(char **maptmp, int alpha, s_tab *tab)
{
	int		j;
	int		tmpi;
	int		tmpj;

	tmpi = tab->co[alpha - 65][0];
	tmpj = tab->co[alpha - 65][1];
	j = tmpj;
	while (maptmp[tmpi] != '\0')
	{
		tmpj = j;
		while (maptmp[tmpi][tmpj] != '\0')
		{
			if (maptmp[tmpi][tmpj] == alpha)
				maptmp[tmpi][tmpj] = '.';
			tmpj++;
		}
		tmpi++;
	}
	return (maptmp);
}

s_tetri	get_info(s_tetri info, int alpha)
{
	info.start = start_finder(info, alpha);
	info.width = get_width(info, alpha);
	info.height = get_height(info, alpha);
	info.alpha = alpha;
	info.y = info.start;
	return (info);
}

void	set_ij(s_tab *tab, int alpha, int who)
{
	if (who == 1)
	{
		tab->i = tab->i + 1;
		tab->j = 0;
	}
	else if (who == 2)
	{
		tab->co[alpha - 65][1] = 0;
		tab->co[alpha - 65][0] += 1;
	}
}

char	**false_test(s_tetri *info, s_tab *tab, char **map, char **form)
{
	tab->j = tab->j + 1;
	if (tab->j >= tab->size)
	{
		if (tab->i < tab->size - 1)
			set_ij(tab, info->alpha, 1);
		else if (info->alpha == 'A')
		{
			info->y = -1;
			return (map);
		}
		else
		{
			info->alpha -= 1;
			info->forme = form[info->alpha - 65];
			*info = get_info(*info, info->alpha);
			map = del_alpha(map, info->alpha, tab);
			tab->i = tab->co[info->alpha - 65][0];
			if (tab->co[info->alpha - 65][1] < tab->size - 1)
				tab->co[info->alpha - 65][1] = tab->co[info->alpha - 65][1] + 1;
			else
				set_ij(tab, info->alpha, 2);
			info->y = -2;
		}
	}
	return (map);
}

char	**true_test(s_tetri *info, s_tab *tab, char **maptmp)
{
	if (info->forme[info->y++] == info->alpha)
		maptmp[tab->i][tab->j] = info->alpha;
	if (info->y == info->start + info->width)
	{
		info->start = info->start + 4;
		info->y = info->start;
		tab->i = tab->i + 1;
		tab->j = tab->co[info->alpha - 65][1];
	}
	else
	{
		tab->j = tab->j + 1;
		if (tab->j >= tab->size)
		{
			if (tab->i < tab->size - 1)
				tab->i = tab->i + 1;
			tab->j = 0;
		}
	}
	return (maptmp);
}

char	**linesave(s_tetri *info, s_tab *tab, char **map, char **form)
{
	tab->i = tab->co[info->alpha - 65][0];
	tab->j = tab->co[info->alpha - 65][1];
	while (map[tab->i] != '\0' && info->forme[info->y] != '\0' && info->y < 16)
	{
		if ((!tab->test) && formalloc(map, *tab, *info) == 1)
		{
			tab->test = formalloc(map, *tab, *info);
			tab->co[info->alpha - 65][0] = tab->i;
			tab->co[info->alpha - 65][1] = tab->j;
		}
		if (tab->test)
			map = true_test(info, tab, map);
		else if ((map = false_test(info, tab, map, form)))
		{
			if (info->y == -1)
				return (NULL);
		}
	}
	return (map);
}

void	set_tab(int alpha, int alphamax, s_tab *tab)
{
	alpha = 'A';
	while (alpha <= alphamax)
	{
		tab->co[alpha - 65][0] = 0;
		tab->co[alpha - 65][1] = 0;
		alpha++;
	}
}

void	tab_zero(s_tab *tab, int size)
{
	tab->i = 0;
	tab->j = 0;
	tab->test = 0;
	tab->size = size;
}

void	tab_co_zero(s_tab *tab, int alpha)
{
	tab->co[alpha - 65][0] = 0;
	tab->co[alpha - 65][1] = 0;
}

char	**square_former(int size, char **form, int alphamax)
{
	s_tab		tab;
	int			alpha;
	s_tetri		info;
	char		**maptmp;

	alpha = 'A';
	maptmp = map_maker(size);
	set_tab(alpha, alphamax, &tab);
	while (alpha <= alphamax)
	{
		tab_zero(&tab, size);
		info.forme = form[alpha - 65];
		info = get_info(info, alpha);
		maptmp = linesave(&info, &tab, maptmp, form);
		if (info.y == -1)
			return (square_former(size + 1, form, alphamax));
		else if (info.y == -2)
			alpha--;
		else
		{
			alpha++;
			tab_co_zero(&tab, alpha);
		}
	}
	return (maptmp);
}

void	if_line(char **line, int **alphamax)
{
	if (**line == '\0')
		**alphamax = **alphamax + 1;
	else
		while (ft_strchr(*line, '#'))
			*(ft_strchr(*line, '#')) = **alphamax;
}

int		minsize_finder(int alphamax)
{
	int		minsize;

	minsize = 0;
	while (minsize * minsize < (alphamax - 64) * 4)
		minsize++;
	return (minsize);
}

int		detection(char **av, char ***form, int *alphamax)
{
	int		fd;
	char	*line;
	char	**s;
	char	*tmp;

	tmp = NULL;
	s = NULL;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (!(s = malloc(sizeof(char**) * 35)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if_line(&line, &alphamax);
		if (s[*alphamax - 65])
		{
			tmp = s[*alphamax - 65];
			s[*alphamax - 65] = ft_strjoin(tmp, line);
			ft_strdel(&tmp);
		}
		else
			s[*alphamax - 65] = ft_strdup(line);
	}
	*form = s;
	return (0);
}

int		tetris_cat(char **av)
{
	int		size;
	char	**form;
	int		alphamax;
	char	**map;
	int		k;

	alphamax = 'A';
	detection(av, &form, &alphamax);
	size = minsize_finder(alphamax);
	map = square_former(size, form, alphamax);
	k = 0;
	while (map[k])
	{
		ft_putstr(map[k++]);
		ft_putchar('\n');
	}
	return (0);
}
