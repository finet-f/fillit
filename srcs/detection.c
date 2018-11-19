/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detection.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 15:00:33 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 09:52:04 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	ft_strdel(&s);
	return (maptmp);
}

int		formalloc(char **maptmp, s_tab tab, s_tetri info)
{
	int		coord[3];
	int		start;
	int		i;
	int		j;

	coord[0] = tab.i;
	coord[1] = tab.j;
	i = tab.i;
	j = tab.j;
	coord[2] = info.start;
	start = info.start;
	while (i != coord[0] + info.height && i < tab.size && coord[2] < 16)
	{
		j = coord[1];
		while (j != coord[1] + info.width && j < tab.size && coord[2] < 16)
			if (maptmp[i][j++] != '.' && info.forme[start] == info.alpha)
				return (0);
			else if (++start == coord[2] + info.width)
			{
				coord[2] = coord[2] + 4;
				start = coord[2];
			}
		i++;
	}
	if (j == coord[1] + info.width && i == coord[0] + info.height)
		return (1);
	else if (j >= tab.size && i >= tab.size)
		return (2);
	return (0);
}

char	**del_alpha(char **maptmp, int alpha, int tmpi, int tmpj)
{
	int		j;

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

s_tetri		get_info(s_tetri info, int alpha)
{
	info.start = start_finder(info, alpha);
	info.width = get_width(info, alpha);
	info.height = get_height(info, alpha);
	info.alpha = alpha;
	return (info);
}

char	**false_test(s_tetri *info, s_tab *tab, char **maptmp)
{
	tab->j = tab->j + 1;
	if (tab->j >= tab->size)
	{
		if (tab->i < tab->size - 1)
		{
			tab->i = tab->i + 1;
			tab->j = 0;
		}
		else if (info->alpha == 'A')
			return (NULL);
		else
		{
			*info = *info->previous;
			maptmp = del_alpha(maptmp, info->alpha, tab->coord[info->alpha - 65][0], tab->coord[info->alpha - 65][1]);
			tab->i = tab->coord[info->alpha - 65][0];
			if (tab->coord[info->alpha - 65][1] < tab->size - 1)
				tab->j = tab->coord[info->alpha - 65][1] + 1;
			else
			{
				tab->j = 0;
				tab->i += 1;
			}
		}
	}
	return (maptmp);
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
		tab->j = tab->coord[info->alpha - 65][1];
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

char	**linesave(s_tetri info, s_tab tab, char **maptmp)
{
	while (maptmp[tab.i] != '\0' && info.forme[info.y] != '\0' && info.y < 16)
	{
		printf("i = %d\nj = %d\nsize = %d\n\n", tab.i, tab.j, tab.size);
		if ((!tab.test) && formalloc(maptmp, tab, info) == 1)
		{
			tab.test = formalloc(maptmp, tab, info);
			tab.coord[info.alpha - 65][0] = tab.i;
			tab.coord[info.alpha - 65][1] = tab.j;
		}
		if (tab.test)
			maptmp = true_test(&info, &tab, maptmp);
		else
			if ((maptmp = false_test(&info, &tab, maptmp)))
				return (NULL);
	}
	return (maptmp);
}
int		square_former(int size, char **form, int alphamax)
{
	s_tab		tab;
	int			alpha;
	s_tetri		info;
	char		**maptmp;
	int			k;

	k = 0;
	alpha = 'A';
	tab.size = size;
	maptmp = map_maker(tab.size);
	tab.i = 0;
	info.forme = form[alpha - 65];
	info.alpha = alpha;
	info.previous = NULL;
	while (alpha <= alphamax)
	{
		*info.next = new_piece(info, alpha + 1, form[alpha - 64]);
		tab.i = 0;
		tab.j = 0;
		info = get_info(info, alpha);
		info.y = info.start;
		tab.test = 0;
		maptmp = linesave(info, tab, maptmp);
		if (maptmp != NULL)
			tab.test = 1;
		alpha++;
		info = *info.next;
		fgetc(stdin);
		printf("alpha = %c\nalphamax = %c\n\n", info.alpha, alphamax);
		if (!tab.test)
			square_former(size + 1, form, alphamax);
	}
	while (maptmp[k] != '\0')
		printf("map = %s\n", maptmp[k++]);
	fgetc(stdin);
	printf("lol");
	fgetc(stdin);
	return (0);
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
	
	alphamax = 'A';
	detection(av, &form, &alphamax);
	size = minsize_finder(alphamax);
	square_former(size, form, alphamax);
	return (0);
}
