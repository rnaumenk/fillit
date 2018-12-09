/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:47:49 by rnaumenk          #+#    #+#             */
/*   Updated: 2017/12/06 12:47:51 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		count;
	int		add;
	char	**figures;
	char	*map;

	if (argc == 1 || argc >= 3)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(str = validation(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	add = -1;
	count = (ft_strlen(str) + 1) / 21;
	figures = create_figures(str, count, 21);
	while (!(fill_this_shit(map = create_map(count, ++add), figures, 'A')))
		free(map);
	ft_putstr(map);
	free(map);
	return (0);
}
