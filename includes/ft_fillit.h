/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:58:03 by ssettle           #+#    #+#             */
/*   Updated: 2019/05/15 00:09:03 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*
** MACROS
*/

# define CHECK_IF_FAL(x)		if (x) return (0)

/*
** Read
*/

char	***enter_matrix(int size, int a, int b, char c);
char	**make_row(int x, int y, char c);
char	**istrings(char *path, int size);
char	***get_it_started(char *path);

int		clear_all(char ***matrix);
int		clear_column(char ***matrix, int n, int i, int x);
int		clear_row(char ***matrix);
int		fill_up(char ***matrix, char **str);
int		free_row(char **row);
int		ilength(char *path);
int		num_pieces(char ***piece);
int		print_row(char **row);
int		squareroot(int i);
int		valid(char *piece);

/*
** Validate
*/

int		piece_czech(char ***str, int n, int i);
int		valid_piece(char **str, int n, int i);

/*
** Solve
*/

int		is_this_legit(char **row, char **piece, int x, int y);
int		my_brain(char **row, char ***piece, int i);
int		put_it_there(char **row, char **piece, int x, int y);
int		ten_second_tidy(char **row, char **piece, int x, int y);
int		work(char ***piece);
int    colorcodes(int x);
/*
** Compile
*/

int		main(int argc, char **argv);

#endif
