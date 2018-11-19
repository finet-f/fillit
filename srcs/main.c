/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 14:26:11 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 11:07:37 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"

void error(void)
{
  ft_putstr_error("Error");
  return ;
}

int		main(int ac, char **av)
{
        int                             fd;
        int                             i;
        char                    *dest;
	s_tetri          tetris;

        i = 0;
        if (ac == 0)
          return (0);
        if ((fd = open(av[1], O_RDONLY)) == -1)
	  return (-1);
        dest = read_file(fd);
        printf("%zu\n", ft_strlen(dest));
        ft_putstr(dest);
        tetris.comp = get_tetriminos();
	//	if (!(check_tetriminos(dest, tetris.comp) && check_recur(dest) && check_backn(dest) && check_pcs(dest) && check_char(dest) && check_nb_line(dest)))
	//{
	//  error();
	//  return (0);
	//}
        printf("Tetriminos valides/invalides = %d.\n"
	       , check_tetriminos(dest, tetris.comp));
        printf("Recurence des pieces = %d.\n", check_recur(dest));
        printf("Nombre de backN = %d.\n", check_backn(dest));
        printf("Nombre de char/lignes = %d.\n", check_pcs(dest));
        printf("Uniquement des '#' ou '.' = %d.\n\n", check_char(dest));
        printf("Nombre de ligne par pieces = %d.\n", check_nb_line(dest));
	close(fd);
	tetris_cat(av);
	return (0);
}
