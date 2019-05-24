/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_the_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:12:28 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/15 00:19:26 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int		squareroot(int i)
{
	int x;

	while (i > 1)
	{
		x = 1;
		while (x * x <= i)
		{
			if (x * x == i)
				return (x);
			x++;
		}
		i++;
	}
	return (0);
}

int		num_pieces(char ***piece)
{
	int i;

	i = 0;
	while (piece[i] != 0)
		i++;
	return (i);
}

char	**make_row(int x, int y, char c)
{
	int		a;
	int		b;
	char	**row;

	a = 0;
	b = 0;
	row = (char**)malloc(sizeof(char*) * (y + 1)); //malloc
	while (a < y)
	{
		row[a] = (char*)malloc(sizeof(char) * (x + 1)); //malloc
		while (b < x)
			row[a][b++] = c;
		row[a][b] = 0;
		b = 0;
		a++;
	}
	row[a] = NULL;
	return (row);
}

int		free_row(char **row)
{
	int		a;
	int b;

	a = 0;
	b = 0;
	while (row[a])// != '\0')
	{
		free(row[a]); //free
		a++;
	}
	free(row); //free
	row = NULL;
	return (0);
}

int		print_row(char **row)
{
	int		a;
	int		b;
		
	a = 0;
	b = 0;
	while (row[a] != 0)
	{
		while (row[a][b])
		{
			colorcodes(row[a][b] - 65);
			if (row[a][b] == '.')
				printf("\e[1;37m");
			printf("%c", row[a][b]);
			b++;
		}
		printf("\n");
		b = 0;
		a++;
	}
	return (0);
}
