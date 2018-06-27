/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "my.h"

int	find_straight(int *tab)
{
	if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3 &&
	    tab[3] == 4 && tab[4] == 5)
		return (1);
	if (tab[0] == 2 && tab[1] == 3 && tab[2] == 4 &&
	    tab[3] == 5 && tab[4] == 6)
		return (1);
	return (0);
}

int	find_pair(int *tab, t_mapsize *ms)
{
	int	count = 0;

	ms->valalgo = 0;
	for (int i = 0; i < 5; ++i)
		for (int j = i + 1; j < 5; ++j)
			if (tab[i] == tab[j])
			{
				if (count == 0)
					ms->valalgo = tab[i];
				count++;
			}
	return (count);
}

int	my_algo(t_mapsize *ms)
{
	int	*tab = malloc(sizeof(int) * 5);

	tab[0] = ms->de1;
	tab[1] = ms->de2;
	tab[2] = ms->de3;
	tab[3] = ms->de4;
	tab[4] = ms->de5;
	if (find_straight(tab) == 1)
		return (5);
	else
		return (find_pair(tab, ms));
}
