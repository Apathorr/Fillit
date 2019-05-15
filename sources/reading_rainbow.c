/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_rainbow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:57:30 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/14 18:39:14 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int		valid(char *piece)
{
	int		x;
	int		n;

	x = 0;
	n = 0;
	while (x < 20)
	{
		n += piece[x];
		x++;
		if (x % 5 == 0 && piece[x - 1] != '\n')
			return (1);
	}
	if (!(piece[x] == 0 || piece[x] == '\n'))
		return (2);
	if (n != 732)
		return (3);
	return (0);
}

int		ilength(char *path)
{
	int		fd;
	int		x;
	char	*buf;
	int		c;
	int		y;

	c = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = ft_strnew(21);
	while ((x = read(fd, buf, 21)))
	{
		if (x < 20 || valid(buf))
			return (0);
		c++;
		y = x;
	}
	if (y != 20)
		return (0);
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (c);
}

char	**istrings(char *path, int size)
{
	int		fd;
	int		x;
	int		i;
	char	*buf;
	char	**out;

	i = 0;
	buf = ft_strnew(21);
	out = (char**)ft_memalloc(sizeof(char *) * (size + 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((x = read(fd, buf, 21)))
	{
		out[i] = ft_strdup(buf);
		i++;
	}
	free(buf);
	if (close(fd) == -1)
		return (NULL);
	return (out);
}

char	***wrong(void)
{
	ft_putendl("error");
	return (NULL);
}

char	***get_it_started(char *path)
{
	int		size;
	char	***matrix;
	char	**str;
	int		i;

	i = 0;
	size = 0;
	size = ilength(path);
	if (!size)
		return (wrong());
	str = istrings(path, size);
	if (!str)
		return (wrong());
	matrix = enter_matrix(size, 4, 4, '.');
	if (!matrix)
		return (wrong());
	fill_up(matrix, str);
	if (piece_czech(matrix, 0, 0) == 0)
		return (wrong());
	clear_all(matrix);
	while (str[i])
		free(str[i++]);
	free(str);
	return (matrix);
}
