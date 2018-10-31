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

void initialisation(t_tetri *liste)
{
  liste->start = NULL;
  liste->end = NULL;
  taille = 0;
}

int insert_list(t_tetri *liste, char **tetri, int width, int height)
{
  t_tetri *new_elem;
  if ((new_elem = malloc(new_elem)) == NULL)
    return (-1);
  ft_strcpy(new_elem->tetri, tetri);
  ft_strcpy(new_elem->width, width);
  ft_strcpy(new_elem->height, height);
  new_elem->prev = liste->start;
  new_elem->next = liste->end;
  liste->start = new_elem;
  liste->end = new_elem;
  liste->size++;
  return (0);
}

int insert_elem_end_liste (t_tetri *liste, char **tetri, int width, int height)
{
  t_tetri *new_elem;
  if ((new_elem = malloc(new_elem)) == NULL)
    return (-1);
  ft_strcpy(new_elem->tetri, tetri);
  ft_strcpy(new_elem->width, width);
  ft_strcpy(new_elem->height, height);
  new_elem->next = NULL;
  new_elem->prev = liste->end;
  liste->end->next = new_elem;
  liste->fin = new_elem;
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
    liste->start->prev == NULL;
  free(del_elem->tetri);
  free(del_elem->width);
  free(del_elem->height);
  free(del_elem);
  liste->size--;
  return (0);
}

{
    while (liste->size > 0)
        supp(liste);
}