/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:59 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 10:32:55 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct tetri
{
  char *forme;
  int  alpha;
  int  width;
  int  height;
  int  start;
  int  y;
  char **comp;
  struct tetri *previous;
  struct tetri *next;
} s_tetri;

typedef struct tab
{
  int size;
  int i;
  int j;
  char *comp;
  int test;
  int coord[26][2];
} s_tab;

int tetris_cat(char **av);
int get_height(s_tetri info, int alpha);
int get_width(s_tetri info, int alpha);
s_tetri new_piece(s_tetri info, int alpha, char *form);
int start_finder(s_tetri info, int alpha);
int detection(char **av, char ***form, int *alphamax);
int square_former(int size, char **form, int alphamax);
char **linesave(s_tetri info, s_tab tab, char **maptmp);
char **true_test(s_tetri *info, s_tab *tab, char **maptmp);
char **false_test(s_tetri *info, s_tab *tab, char **maptmp);
s_tetri get_info(s_tetri info, int alpha);
char **del_alpha(char **maptmp, int alpha, int tmpi, int tmpj);
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
//void initialisation(t_tetri *liste);
//int insert_list(t_tetri *liste, char **tetris, char **dest_tetris);
//int insert_elem_end_liste (t_tetri *liste, char **tetris, char **dest_tetris);
//int supp(t_tetri *liste);
//void affiche(t_tetri *liste);
//void del_list(t_tetri *liste);
int main(int ac, char **av);
void ft_putchar_error(char c);
void ft_putstr_error(char *str);

#endif
