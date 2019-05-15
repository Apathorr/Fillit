/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legit_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:28:15 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/10 18:05:02 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int		valid_piece(char **str, int n, int i)
{
	int		x;

	x = 0;
	if (i < 3)
	{
		if (str[n][i + 1] == str[n][i])
			x++;
	}
	if (n < 3)
	{
		if (str[n + 1][i] == str[n][i])
			x++;
	}
	if (i > 0)
	{
		if (str[n][i - 1] == str[n][i])
			x++;
	}
	if (n > 0)
	{
		if (str[n - 1][i] == str[n][i])
			x++;
	}
	return (x);
}

int		piece_czech(char ***str, int n, int i)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a])
	{
		while (str[a][n])
		{
			while (str[a][n][i])
			{
				if (str[a][n][i] >= 65 && str[a][n][i] <= 90)
					b += valid_piece(str[a], n, i);
				i++;
			}
			i = 0;
			n++;
		}
		if (b < 6)
			return (0);
		b = 0;
		n = 0;
		a++;
	}
	return (1);
}
