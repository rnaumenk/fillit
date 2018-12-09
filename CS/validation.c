/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:43:43 by rnaumenk          #+#    #+#             */
/*   Updated: 2017/12/05 10:43:45 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		four_x_four(char *s, int i, int j)
{
	int		l;

	l = 4;
	while (--j >= 0)
	{
		if (s[i] == '\n' && l)
			return (0);
		if (s[i] == '\n' && !l)
			l = 5;
		l--;
		i++;
	}
	return (1);
}

static int		connection(char *s, int i, int j)
{
	int		connect;

	j = 21;
	connect = 0;
	while (--j >= 0)
	{
		if (s[i] == '#')
		{
			if (i > 0 && s[i - 1] == '#')
				connect++;
			if (s[i + 1] == '#')
				connect++;
			if ((i - 5) >= 0 && s[i - 5] == '#' && j <= 15)
				connect++;
			if ((size_t)(i + 5) < ft_strlen(s) && s[i + 5] == '#' && j >= 5)
				connect++;
		}
		i++;
	}
	if (connect < 6)
		return (0);
	return (1);
}

static int		check_the_square(char *s, int i, int j)
{
	int		dot;
	int		sharp;
	int		newline;

	dot = 0;
	sharp = 0;
	newline = 0;
	while (--j >= 0 && s[i])
	{
		if (s[i] == '.')
			dot++;
		if (s[i] == '#')
			sharp++;
		if (s[i] == '\n')
			newline++;
		i++;
	}
	if (!s[i] && (dot != 12 || sharp != 4 || newline != 4
		|| !connection(s, i - 20, 20) || !four_x_four(s, i - 20, 18)))
		return (0);
	else if (s[i] && (dot != 12 || sharp != 4 || newline != 5
		|| !connection(s, i - 21, 21) || !four_x_four(s, i - 21, 19)))
		return (0);
	return (1);
}

static int		check_the_file(char *s)
{
	int		i;
	int		j;

	j = 20;
	i = -1;
	while (s[++i])
	{
		if (!j && !(check_the_square(s, i - 20, 21)))
			return (0);
		else if (!j && check_the_square(s, i - 20, 21))
		{
			j = 20;
			i++;
		}
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		j--;
	}
	if (!s[i] && !j && !(check_the_square(s, i - 20, 20)))
		return (0);
	return (1);
}

char			*validation(char *str)
{
	int		i;
	int		fd;
	int		res;
	char	buf[BUF_SIZE + 1];
	char	*s;

	i = -1;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	res = read(fd, buf, BUF_SIZE);
	close(fd);
	buf[res] = '\0';
	if (!(s = (char*)malloc(sizeof(char) * res)))
		return (0);
	while (++i <= res)
		s[i] = buf[i];
	if (!check_the_file(s) || (ft_strlen(buf) + 1) % 21 ||
		((ft_strlen(s) + 1) / 21) > 26)
		return (0);
	return (s);
}
