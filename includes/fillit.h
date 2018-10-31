/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:59 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:07:41 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

int main(int ac, char **av);
void initialisation(t_tetri *liste);
int insert_list(t_tetri *liste, char **tetri, int width, int height);
int insert_elem_end_liste (t_tetri *liste, char **tetri, int width, int height);
int supp(t_tetri *liste);
void free_list(t_tetri *liste);

typedef struct s_tetri
{
  int width;
  int height;
  char **content;
  struct s_tetri *next;
  struct s_tetri *prev;
  struct s_tetri *start;
  struct s_tetri *end;
  size_t size;
} t_tetri;

#endif
