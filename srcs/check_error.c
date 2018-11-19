/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_file.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 12:08:20 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 11:24:11 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/fillit.h"

char				**get_tetriminos(void)
{
	char			**str;

	if (!(str = (char**)malloc(sizeof(*str) * 19)))
		return (NULL);
	str[0] = ".##.##.|2x3";
	str[1] = "#...##...#|3x2";
	str[2] = "##...##|2x3";
	str[3] = ".#..##..#|3x2";
	str[4] = "##..##|2x2";
	str[5] = ".#..###.|2x3";
	str[6] = "#...##..#|3x2";
	str[7] = "###..#..|2x3";
	str[8] = ".#..##...#|3x2";
	str[9] = "#...#...##|3x2";
	str[10] = "###.#.|2x3";
	str[11] = "##...#...#|3x2";
	str[12] = "..#.###|2x3";
	str[13] = ".#...#..##|3x2";
	str[14] = "###...#|2x3";
	str[15] = "##..#...#|3x2";
	str[16] = "#...###|2x3";
	str[17] = "#...#...#...#|4x1";
	str[18] = "####|1x4";
	return (str);
}

char				*get_piece(char *tmp, char *str)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	if (!tmp || !str)
		return (0);
	while (tmp[i])
	{
		j = 0;
		k = 0;
		while (str[j] == tmp[i + k])
		{
			if (!str[j + 1] || str[j + 1] == '|')
				return (str);
			j++;
			tmp[i + k + 1] == '\n' ? k += 2 : k++;
		}
		i++;
	}
	return (NULL);
}

int					check_tetriminos(char *dest, char **str)
{
	char			*tmp;
	int				i;
	int				found;
	int				l;

	i = 0;
	while (ft_strlen(dest) >= 20)
	{
		found = 0;
		if (!(tmp = ft_strsub(dest, 0, 20)))
			return (-1);
		while (i < 19)
			if (get_piece(tmp, str[i++]))
				found = 1;
		i = 0;
		ft_strdel(&tmp);
		l = ft_strlen(dest);
		dest = ft_strfsub(&dest, l < 21 ? 20 : 21, l < 21 ? l - 20 : l - 21);
		if (!found)
			return (-1);
		free(tmp);
	}
	free(dest);
	return (0);
}

char				*read_file(const int fd)
{
	char			*buf;
	char			*tmp;
	char			*file;
	int				rt;

	if (!(buf = ft_strnew(1000 + 1)))
		return (NULL);
	if (!(file = ft_strnew(546)))
		return (NULL);
	while ((rt = read(fd, buf, 1000)) > 0)
	{
		buf[rt] = '\0';
		if (!(tmp = ft_strjoin(file, buf)))
			return (NULL);
		ft_strdel(&file);
		file = tmp;
	}
	free(buf);
	return (file);
}

int					main(int argc, char **argv)
{
	int				fd;
	int				i;
	char			*dest;
	s_tetri	tetris;

	i = 0;
	if (argc == 0)
	  return (0);
	dest = NULL;
	dest = malloc (sizeof(char) * 1001);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	dest = read_file(fd);
	printf("%zu\n", ft_strlen(dest));
	ft_putstr(dest);
	tetris.comp = get_tetriminos();
	printf("Tetriminos valides/invalides = %d.\n"
			, check_tetriminos(dest, tetris.comp));
	printf("Recurence des pieces = %d.\n", check_recur(dest));
	printf("Nombre de backN = %d.\n", check_backn(dest));
	printf("Nombre de char/lignes = %d.\n", check_pcs(dest));
	printf("Uniquement des '#' ou '.' = %d.\n\n", check_char(dest));
	printf("Nombre de ligne par pieces = %d.\n", check_nb_line(dest));
	return (0);
}
