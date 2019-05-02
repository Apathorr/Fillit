/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   love_and_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:58:54 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/02 03:36:19 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fillit.h"

char	***enter_matrix(int size, int a, int b, char c)
{
	char	***neo;
	int		i;
	int		n;
	int		k;

	i = 0;
	n = 0;
	neo = (char***)malloc(sizeof(char**) * (size + 1));
	while (i < size)
	{
		neo[i] = (char**)malloc(sizeof(char*) * (a + 1));
		while (n < a)
		{
			k = 0;
			neo[i][n] = ft_strnew(b);
			while (k < b)
				neo[i][n][k++] = c;
			n++;
		}
		neo[i][n] = NULL;
		i++;
		n = 0;
	}
	neo[i] = NULL;
	return (neo);
}

int		fill_up(char ***matrix, char **str)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	while (matrix[a])
	{
		while (matrix[a][b])
		{
			while (matrix[a][b][c])
			{
				if (str[a][b * 5 + c++] == '#')
					matrix[a][b][c - 1] = str[a][b * 5 + c - 1] + 30 + a;
			}
			b++;
			c = 0;
		}
		a++;
		b = 0;
	}
}

int		clear_row(char ***matrix)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	while (matrix[a])
	{
		while (matrix[a][b])
		{
			if (!strcmp(matrix[a][b], "...."))
			{
				c = b--;
				while (matrix[a][c])
				{
					matrix[a][c] = matrix[a][c + 1];
					c++;
				}
			}
			b++;
		}
		a++;
		b = 0;
	}
	return (0);
}

int		clear_column(char ***matrix, int n, int i, int x)
{
	int		a;

	a = 0;
	while (matrix[n][i])
	{
		if (matrix[n][i][x] == '.')
			a++;
		i++;
	}
	if (a == i)
	{
		i = 0;
		while (matrix[n][i])
		{
			a = x;
			while (matrix[n][i][a])
			{
				matrix[n][i][a] = matrix[n][i][a + 1];
				a++;
			}
			i++;
		}
		x--;
	}
	return (x);
}

int		clear_all(char ***matrix)
{
	int		a;
	int		b;
	

	a = 0;
	b = 0;
	while (matrix[a])
	{
		while (matrix[a][0][b])
		{
			b = clear_column(matrix, a, 0, b);
			b++;
		}
		a++;
		b = 0;
	}
	return (0);
}