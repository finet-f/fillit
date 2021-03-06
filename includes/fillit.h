/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 14:27:04 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 13:20:30 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef		_FILLIT_H
#define		_FILLIT_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct		tetri
{
	char			*forme;
	int				alpha;
	int				width;
	int				height;
	int				start;
	int				y;
  char **comp;
	struct tetri	*previous;
	struct tetri	*next;
}					s_tetri;
typedef struct		tab
{
	int				size;
	int				i;
	int				j;
	int				test;
	int				co[26][2];
}					s_tab;

int tetris_cat(char **av);
int get_height(s_tetri info, int alpha);
void set_ij(s_tab *tab, int alpha, int who);
void tab_co_zero(s_tab *tab, int alpha);
void tab_zero(s_tab *tab, int size);
void set_tab(int alpha, int alphamax, s_tab *tab);
int get_width(s_tetri info, int alpha);
s_tetri new_piece(s_tetri info, int alpha, char *form);
int start_finder(s_tetri info, int alpha);
int detection(char **av, char ***form, int *alphamax);
char **square_former(int size, char **form, int alphamax);
int get_form(char **form, int alphamax);
char **linesave(s_tetri *info, s_tab *tab, char **maptmp, char **form);
char **true_test(s_tetri *info, s_tab *tab, char **maptmp);
char **false_test(s_tetri *info, s_tab *tab, char **map, char **form);
s_tetri get_info(s_tetri info, int alpha);
char **del_alpha(char **maptmp, int alpha, s_tab *tab);
int formalloc(char **maptmp, s_tab tab, s_tetri info);
char **map_maker(int size);
void if_line(char **line, int **alphamax);
int check_recur(char *dest);
int check_backn(char *dest);
int check_pcs(char *dest);
int check_tetriminos(char *dest, char **str);
char *get_piece(char *tmp, char *str);
char **get_tetriminos(void);
char *read_file(int fd);
int check_char(char *dest);
int check_nb_line(char *dest);

#endif
