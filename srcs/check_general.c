/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_general.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 14:00:03 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:16:02 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int			check_char(char *dest)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] != '\n' && dest[i] != '.' && dest[i] != '#')
			return (-1);
		i++;
	}
	return (0);
}

int			check_pcs(char *dest)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		if (dest[i] == '\n')
		{
			if (j != 4)
				return (-1);
			j = 0;
		}
		while (dest[i] == '\n')
			i++;
		i++;
		j++;
	}
	return (0);
}

int			check_nb_line(char *dest)
{
	int		i;
	float	j;
	float	k;

	k = 0;
	j = 0;
	i = 0;
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	while (dest[i])
	{
		if (dest[i] == '\n' && dest[i + 1] == '\n')
			k++;
		if (dest[i] == '\n')
			j++;
		i++;
	}
	printf("j : %f\n", j);
	printf("k : %f\n", k);
	j = j - (k - 1);
	printf("k : %f\n", k);
	printf("j : %f\n", j);
	k++;
	printf("k : %f\n", k);
	printf("j/k : %f\n", j/k);
	if (j / k != 4)
		return (-1);
	return (0);
}

int			check_backn(char *dest)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		if (dest[i] == '\n' && dest[i + 1] == '\n')
			j++;
		i++;
	}
	j++;
	if (j > 26)
		return (-1);
	return (0);
}

int			check_recur(char *dest)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (dest[i])
	{
		if (dest[i] == '\n' && dest[i - 1] != '\n')
		{
			j++;
		}
		if (dest[i] == '\n' && dest[i + 1] == '\n')
		{
			if (j != 4)
				return (-1);
			if (j == 4)
				j = 0;
		}
		i++;
	}
	return (0);
}
