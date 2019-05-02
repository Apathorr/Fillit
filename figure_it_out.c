/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_it_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:27:03 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/01 19:28:19 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fillit.h"

int		put_it_there(char **row, char **piece, int x, int y)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (piece[a] != 0)
	{
		while (piece[a][b] != 0)
		{
			if (piece[a][b] != '.')
			{
				row[x + a][y + b] = piece[a][b];
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

int		ten_second_tidy(char **row, char **piece, int x, int y)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (piece[a] != 0)
	{
		while (piece[a][b] != 0)
		{
			if (piece[a][b] != '.')
			{
				row[x + a][y + b] = '.';
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

int		is_this_legit(char **row, char **piece, int x, int y)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (piece[a] != 0)
	{
		if (row[x + a] == 0)
			return (0);
		while(piece[a][b] != 0)
		{
			if (row[x + a][y + b] == 0)
				return (0);
			if (piece[a][b] != '.' && row[x + a][y + b] != '.')
				return (0);
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}

int		my_brain(char **row, char **piece, int i)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (piece[i] == 0)
		return (0);
	while (row[a] != 0)
	{
		while (row[a][b] != 0)
		{
			if (is_this_legit(row, piece[i], a, b))
			{
				put_it_there(row, piece[i], a, b);
				if (my_brain(row, piece, i + 1))
					return (0);
				ten_second_tidy(row, piece[i], a, b);
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}

int		work(char ***piece)
{
	int		tiny;
	char	**row;

	tiny = squareroot(num_pieces(piece) * 4);
	row = (make_row(tiny, tiny, '.'));
	while (my_brain(row, piece, 0))
	{
		tiny++;
		free_row(row);
		row = make_row(tiny, tiny, '.');
	}
	print_row(row);
	return (0);
}
