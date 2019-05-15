/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:47:40 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/14 22:19:55 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_fillit.h"


int		main(int argc, char **argv)
{
	char ***matrix;
	int i;
	int j;
	
	j = 0;
	i = 0;
	if (argc < 2)
		ft_putendl("usage: fillit source_file");
	else if (argc > 2)
		ft_putendl("too many inputs, please reconsider");
	else
	{
		matrix = get_it_started(argv[1]);
		if (!matrix)
			return (1);
		work(matrix);
		return (0);
	}
	return (1);
}
