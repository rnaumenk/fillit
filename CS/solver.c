/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:08:17 by rnaumenk          #+#    #+#             */
/*   Updated: 2017/12/16 19:08:18 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		clear_the_last_one(char *map, int o, int i)
{
	while (map[++i])
		if (map[i] == o)
			map[i] = '.';
}

static int		fillit(char *map, int i, int j, int o)
{
	int		len;
	int		newline;
	int		k;
	int		line;

	len = ft_strlen(map);
	newline = 0;
	k = 0;
	while (map[k++])
		if (map[k] == '\n')
			newline++;
	line = len / newline;
	if (j < 0)
		i += line * (-j / 10) - (-j % 10);
	else if (j > 0)
		i += line * (j / 10) + j % 10;
	if ((map[i] != '.') || i >= len || i < 0)
		return (0);
	map[i] = o;
	return (1);
}

static int		to_fill_or_not_to_fill(char *figure, char *map, int i, int o)
{
	int		n;
	int		k;
	int		newline;
	int		j;

	n = 0;
	newline = 0;
	if (!(fillit(map, i, 0, o)))
		return (0);
	while (figure[n] != '#')
		n++;
	k = n;
	while (figure[n++])
	{
		if (figure[n] == '\n' && newline++ >= 0)
			k += 5;
		if (figure[n] == '#')
		{
			j = (n >= k ? n - k + newline * 10 : n - k - newline * 10);
			if (!(fillit(map, i, j, o)))
				return (0);
		}
	}
	return (1);
}

int				fill_this_shit(char *map, char **figures, int o)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*figures)
		return (1);
	while (*figures && map[i])
	{
		if (to_fill_or_not_to_fill(*figures, map, i + j, o) == 1)
		{
			if (fill_this_shit(map, ++figures, ++o) == 1)
				return (1);
			figures--;
			clear_the_last_one(map, --o, -1);
			j++;
		}
		else if (i++ >= 0)
			clear_the_last_one(map, o, -1);
	}
	return (!map[i] ? 0 : 1);
}
