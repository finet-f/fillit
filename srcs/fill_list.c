#include "fillit.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
  t_tetri *list;
  char **tetriss;
  //int width = 3;
  //int height = 2;
  size_t nbr_pcs;
  char **dest_tetris;
  char *piece;
  char **line;
  int i;
  int p;
  int fd;

  list = NULL;
  nbr_pcs = 10;
  tetriss = NULL;
  
  list = malloc(sizeof(list) * nbr_pcs);
  if (ac != 2)
    {
      ft_putstr("Usage : ./fillit [arg1]\n        only one argument after bin.\n");
      return (-1);
    }
  fd = open(av[1], O_RDONLY);
  i = 0;
  line = malloc(sizeof(char*) * 10);
  while(i < 10)
  {
    line[i++] = malloc(sizeof(char) * 100);
  }
  i = 0;
  while (get_next_line(fd, &piece))
    {
      line[i] = piece;
      i++;
    }
  i = 0;
  tetriss = malloc(sizeof(char*) * 3);
  while(i < 2)
  {
    tetriss[i] = malloc(sizeof(char) * 3);
    i++;
  }
  tetriss[i] = NULL;
  i = 0;
  p = 0;
  while (i < 2)
  {
    while (p < 3)
    {
      tetriss[i][p] = '.';
      p++;
    }
    tetriss[i][p] = '\0';
    i++;
    p = 0;
  }
  tetriss[3] = NULL;
  i = 0;
  p = 0;
   while (tetriss[i])
  {
    while(tetriss[i][p])
        p++;
    ft_putstr(tetriss[i]);
    ft_putchar('\n');
    p = 0;
    i++;
    }
  i = 0;
  dest_tetris = malloc(sizeof(char*) * 2);
  while(i < 2)
  {
    dest_tetris[i] = malloc(sizeof(char) * 3);
    i++;
  }
  initialisation(list);
  insert_list(list, tetriss, dest_tetris);
  affiche(list);
  //insert_elem_end_liste(list, tetriss, dest_tetris);
  del_list(list);
    return (0);
}
