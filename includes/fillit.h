/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:59 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 14:10:33 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct s_tetri
{
  int width;
  int height;
  char **tetris;
  char **comp;
  int *start;
} t_tetri;

int check_recur(char *dest);
int check_backn(char *dest);
int check_pcs(char *dest);
int check_char(char *dest);
int check_nb_line(char *dest);
void initialisation(t_tetri *liste);
int insert_list(t_tetri *liste, char **tetris, char **dest_tetris);
int insert_elem_end_liste (t_tetri *liste, char **tetris, char **dest_tetris);
int supp(t_tetri *liste);
void affiche(t_tetri *liste);
void del_list(t_tetri *liste);
int main(int ac, char **av);

#endif
