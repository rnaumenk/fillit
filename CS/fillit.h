/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:05:30 by rnaumenk          #+#    #+#             */
/*   Updated: 2017/12/16 19:05:31 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 4096

size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*validation(char *str);
char				**create_figures(char *str, int count, int j);
char				*create_map(int count, int add_size);
int					fill_this_shit(char *map, char **figures, int o);

#endif
