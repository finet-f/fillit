/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_tetris.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:36:20 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 16:04:12 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int check_error1(char **tab, int i, int j, int alphamax)
{
  //	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) &&
				(tab[i][j + 2] == alphamax) && (tab[i][j + 5] == alphamax))
			return (0);
		//	if (i + 2 < 4 && i + 1 < 4 && j - 1 >= 0)
		if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) &&
				(tab[i][j + 7] == alphamax) && (tab[i][j + 8] == alphamax))
			return (0);
		//if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) && (tab[i]
				   [j + 5] == alphamax) && (tab[i][j + 6] == alphamax))
			return (0);
		//	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) &&
				(tab[i][j + 2] == alphamax) && (tab[i][j + 6] == alphamax))
			return (0);
		//if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) &&
				(tab[i][j + 4] == alphamax) && (tab[i][j + 8] == alphamax))
			return (0);
		//if (i + 1 < 4 && j - 1 >= 0 && i + 2 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 3] == alphamax) &&
				(tab[i][j + 4] == alphamax) && (tab[i][j + 8] == alphamax))
			return (0);
	return (-1);
}

int check_error2(char **tab, int i, int j, int alphamax)
{
  //	if (j - 1 >= 0 && i + 1 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 3] == alphamax) && (tab[i]
					[j + 4] == alphamax) && (tab[i][j + 5] == alphamax))
			return (0);
		//if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) &&
				(tab[i][j + 5] == alphamax) && (tab[i][j + 8] == alphamax))
			return (0);
		//if (i - 1 >= 0 && j + 1 < 4 && j + 2 < 4)
	  if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) && (tab[i]
					[j + 2] == alphamax) && (tab[i][j + 4] == alphamax))
			return (0);
	  //	if (i + 1 < 4 && j + 1 < 4 && i + 2 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) && (tab[i]
					[j + 5] == alphamax) && (tab[i][j + 9] == alphamax))
			return (0);
		//if (j - 1 > 0 && i + 1 < 4 && j - 2 >= 0)
		if ((tab[i][j] == alphamax) && (tab[i][j + 2] == alphamax) && (tab[i]
					[j + 3] == alphamax) && (tab[i][j + 4] == alphamax))
		    return (0);
		//	if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) &&
				(tab[i][j + 8] == alphamax) && (tab[i][j + 9] == alphamax))
			return (0);
	return (-1);
}

int check_error3(char **tab, int i, int j, int alphamax)
{
  //if (i + 1 < 4 && j + 1 < 4 && j - 1 >= 0)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) && (tab[i]
					[j + 3] == alphamax) && (tab[i][j + 4] == alphamax))
			return (0);
		//if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) && (tab[i]
					[j + 5] == alphamax) && (tab[i][j + 9] == alphamax))
			return (0);
		//if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) && (tab[i]
					[j + 5] == alphamax) && (tab[i][j + 6] == alphamax))
			return (0);
		//if (j + 1 < 4 && i - 1 >= 0 && i - 2 >= 0)
		if ((tab[i][j] == alphamax) && (tab[i][j + 3] == alphamax) && (tab[i]
					[j + 4] == alphamax) && (tab[i][j + 7] == alphamax))
			return (0);
		//if (j + 3 < 4 && j + 2 < 4 && j + 1 < 4)
		if (j % 4 == 0)
		  if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) &&
				(tab[i][j + 2] == alphamax) && (tab[i][j + 3] == alphamax))
			return (0);
		//			if (i + 3 < 4 && i + 2 < 4 && i + 1 < 4)
	  if ((tab[i][j] == alphamax) && (tab[i][j + 4] == alphamax) &&
				(tab[i][j + 8] == alphamax) && (tab[i][j + 12] == alphamax))
			return (0);
	return (-1);
}

int check_error4(char **tab, int i, int j, int alphamax)
{
  //	if (i + 1 < 4 && j + 1 < 4)
		if ((tab[i][j] == alphamax) && (tab[i][j + 1] == alphamax) &&
				(tab[i][j + 4] == alphamax) && (tab[i][j + 5] == alphamax))
			return (0);
	return (-1);
}

int get_form(char **tab, int alphamax)
{
	int i;
	int j;

	i = 0;
	  alphamax = 'A';
	while (tab[i])
	{
	  printf("%c\n\n", alphamax);
	  ft_putstr(tab[i]);
		j = 0;
		while (tab[i][j])
		{
		  printf("%d\n", check_error1(tab, i, j, alphamax));
		  printf("%d\n", check_error2(tab, i, j, alphamax));
		  printf("%d\n", check_error3(tab, i, j, alphamax));
		  printf("%d\n", check_error4(tab, i, j, alphamax));
		  j++;
		}
		  printf("\n");		
		i++;
	  alphamax++;
	}
	return (0);
}
