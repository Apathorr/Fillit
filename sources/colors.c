/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:51:22 by rsmith            #+#    #+#             */
/*   Updated: 2019/05/19 12:42:03 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int   colorcodes(int x)
{

   if (x == 0 || x == 10 || x == 20)
    {
        printf("\e[0;31m");
        return (0);
    }
   if (x == 1 || x == 11 || x == 21)
    {
        printf("\e[0;32m");
        return (0);
    }
   if (x == 2 || x == 12 || x == 22)
    {
        printf("\033[0;33m");
        return (0);
    }
   if (x == 3 || x == 13 || x == 23)
    {
        printf("\033[0;34m");
        return (0);
    }
   if (x == 4 || x == 14 || x == 24)
    {
        printf("\e[0;35m");
        return (0);
    }
   if (x == 5 || x == 15 || x == 25)
    {
        printf("\e[0;36m");
        return (0);
    }
   if (x == 6 || x == 16 || x == 26)
    {
        printf("\e[1;31m");
        return (0);
    }
   if (x == 7 || x == 17)
    {
        printf("\e[1;32m");
        return (0);
    }
   if (x == 8 || x == 18)
    {
        printf("\e[1;33m");
        return (0);
    }
   if (x == 9 || x == 19)
    {
        printf("\e[1;34m");
        return (0);
    }
   return (0);
}
