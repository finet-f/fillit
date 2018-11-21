/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 14:27:04 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:39:44 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef		_FILLIT_H
#define		_FILLIT_H

typedef struct		tetri
{
	char			*forme;
	int				alpha;
	int				width;
	int				height;
	int				start;
	int				y;
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
int		tetris_cat(char **av);
int		get_height(s_tetri info, int alpha);
int		get_width(s_tetri info, int alpha);
int		start_finder(s_tetri info, int alpha);

#endif
