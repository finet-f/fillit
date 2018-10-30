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

typedef struct s_tetri
{
  int width;
  int height;
  char **content;
  struct s_tetri *next;
  struct s_tetri *prev;
} t_tetri;

#endif
