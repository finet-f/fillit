/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_file.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 12:08:20 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:11:35 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char				**get_tetriminos(void)
{
	char			**str;

	if (!(str = (char**)malloc(sizeof(*str) * 19)))
		return (NULL);
	str[0] = ".##.##.";
	str[1] = "#...##...#";
	str[2] = "##...##";
	str[3] = ".#..##..#";
	str[4] = "##..##";
	str[5] = ".#..###.";
	str[6] = "#...##..#";
	str[7] = "###..#..";
	str[8] = ".#..##...#";
	str[9] = "#...#...##";
	str[10] = "###.#.";
	str[11] = "##...#...#";
	str[12] = "..#.###";
	str[13] = ".#...#..##";
	str[14] = "###...#";
	str[15] = "##..#...#";
	str[16] = "#...###";
	str[17] = "#...#...#...#";
	str[18] = "####";
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
	ft_putstr(buf);
	return (buf);
}
