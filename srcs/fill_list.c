/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:59 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 11:16:33 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void initialisation(t_tetri *liste)
{
  liste->start = NULL;
  liste->end = NULL;
  liste->size = 0;
}

char **ft_strcpy_2(char **dst, char **src)
{
  int i;
  int j;

  j = 0;
  i = 0;
  while (src[i])
    {
      while(src[i][j])
	{
	  dst[i][j] = src[i][j];
	  j++;
	}
      dst[i][j] = '\0';
      i++;
      j = 0;
    }
  dst[i] = NULL;
  return (dst);
}

int insert_list(t_tetri *liste, char **tetriss, char **dest_tetris)
{
  t_tetri *new_elem;

  if ((new_elem = malloc(sizeof(new_elem) * 10)) == NULL)
    return (-1);
  ft_strcpy_2(dest_tetris, tetriss);
  //new_elem->width = width;
  //new_elem->height = height;
  new_elem->tetris = dest_tetris;
  new_elem->prev = liste->start;
  new_elem->next = liste->end;
  liste->start = new_elem;
  liste->end = new_elem;
  liste->size++;
  return (0);
}

int insert_elem_end_liste (t_tetri *liste, char **tetriss, char **dest_tetris)
{
  t_tetri *new_elem;
  if ((new_elem = malloc(sizeof(new_elem) * 1)) == NULL)
    return (-1);
  tetriss = NULL;
  ft_strcpy_2(dest_tetris, tetriss);
  //  new_elem->width = width;
  //new_elem->height = height;
  new_elem->tetris = dest_tetris;
  new_elem->next = NULL;
  new_elem->prev = liste->end;
  liste->end->next = new_elem;
  liste->end = new_elem;
  liste->size++;
  return (0);
}

int supp(t_tetri *liste)
{
  t_tetri *del_elem;

  if(liste->size == 0)
    return (-1);
  del_elem = liste->start;
    liste->start = liste->start->next;
  if(liste->start == NULL)
    liste->end = NULL;
  else
    liste->start->prev = NULL;
  free(del_elem->tetris);
  del_elem->width = 0;
  del_elem->height = 0;
  free(del_elem);
  liste->size--;
  return (0);
}

void del_list(t_tetri *liste)
{
    while (liste->size > 0)
        supp(liste);
}

void ft_putstr2(char **str)
{
  int i;

  i = 0;
  while(str)
    {
      ft_putstr(str[i]);
      ft_putchar('\n');
      i++;
    }
}

void affiche(t_tetri *liste)
{
  int i;
  t_tetri *courant;
  courant = liste->start;
  i = 0;
  while(courant != NULL)
    {
      ft_putstr("\n");
      ft_putstr2(courant->tetris);
      courant = courant->next;
      i++;
  }
}
