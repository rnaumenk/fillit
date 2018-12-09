/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remake_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:31:19 by rnaumenk          #+#    #+#             */
/*   Updated: 2017/12/11 15:31:20 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		move_figures_up(char **figures, int n, int up)
{
	int		k;
	int		i;

	k = 0;
	i = 5 * up;
	while (i < 20)
		figures[n][k++] = figures[n][i++];
	while (up)
	{
		if (figures[n][k] == '\n')
		{
			up--;
			k++;
		}
		else
			figures[n][k++] = '.';
	}
}

static void		move_figures_left(char **figures, int n)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	while (figures[n][k + i])
	{
		if (figures[n][k + i] == '\n')
		{
			figures[n][k++] = '.';
			figures[n][k++] = '\n';
		}
		else
		{
			figures[n][k] = figures[n][k + i];
			k++;
		}
	}
}

static char		**remake_figures(char **figures, int count)
{
	int		n;
	int		k;
	int		up;

	n = -1;
	while (++n < count)
	{
		while (figures[n][0] == '.' && figures[n][5] == '.' &&
			figures[n][10] == '.' && figures[n][15] == '.')
			move_figures_left(figures, n);
		up = 0;
		k = 0;
		while (figures[n][k] == '.' || figures[n][k] == '\n')
		{
			if (figures[n][k] == '\n')
				up++;
			k++;
		}
		if (up)
			move_figures_up(figures, n, up);
	}
	return (figures);
}

char			**create_figures(char *str, int count, int j)
{
	char	**figures;
	char	*figure;
	int		i;
	int		n;
	int		k;

	n = 0;
	i = 0;
	k = 0;
	if (!(figures = (char**)malloc(sizeof(char*) * count + 1)))
		exit(0);
	figures[count] = 0;
	while (n < count)
	{
		if (!(figure = (char*)malloc(sizeof(char) * 21)))
			exit(0);
		while (--j)
			figure[k++] = str[i++];
		figure[k] = '\0';
		j = 21;
		k = 0;
		i++;
		figures[n++] = figure;
	}
	return (remake_figures(figures, count));
}

char			*create_map(int count, int add_size)
{
	char	*map;
	int		sizeof_side;
	int		i;
	int		newline;

	sizeof_side = 2;
	i = -1;
	while (sizeof_side * sizeof_side < count * 4)
		sizeof_side++;
	sizeof_side = sizeof_side + add_size;
	newline = sizeof_side + 1;
	if (!(map = (char*)malloc(sizeof(char) * (sizeof_side * sizeof_side +
		sizeof_side + 1))))
		exit(0);
	while (++i < sizeof_side * sizeof_side + sizeof_side)
	{
		map[i] = '.';
		if (!(--newline))
		{
			map[i] = '\n';
			newline = sizeof_side + 1;
		}
	}
	map[i] = '\0';
	return (map);
}
