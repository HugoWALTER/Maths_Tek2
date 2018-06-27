/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h poll
*/

#ifndef MY_H
#define MY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef	struct	s_mapsize
{
	int	N;
	int	n;
	double	p;
	double	variance;
	double	min_95;
	double	max_95;
	double	min_99;
	double	max_99;
	double	x_bar;
}		t_mapsize;

#endif /* !MY_H_ */
