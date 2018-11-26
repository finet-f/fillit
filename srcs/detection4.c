/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detection4.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 13:10:41 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 13:56:08 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			formalloc(char **map, s_tab tab, s_tetri info)
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

char		**del_alpha(char **maptmp, int alpha, s_tab *tab)
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

s_tetri		get_info(s_tetri info, int alpha)
{
	info.start = start_finder(info, alpha);
	info.width = get_width(info, alpha);
	info.height = get_height(info, alpha);
	info.alpha = alpha;
	info.y = info.start;
	return (info);
}

void		set_ij(s_tab *tab, int alpha, int who)
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

char		**false_test(s_tetri *info, s_tab *tab, char **map, char **form)
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
