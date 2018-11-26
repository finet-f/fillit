/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detection3.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 13:08:39 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 13:19:07 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
