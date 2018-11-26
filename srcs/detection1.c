/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detection.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 15:00:33 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 13:13:53 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
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
