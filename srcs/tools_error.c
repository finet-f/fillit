/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   toolserror.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 12:18:04 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 10:39:51 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putstr_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_error(str[i]);
		i++;
	}
}
